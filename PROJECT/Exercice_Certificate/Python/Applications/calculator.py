from PySide6.QtWidgets import QApplication, QWidget, QPushButton, QHBoxLayout, QVBoxLayout, QGridLayout, QLineEdit, QSizePolicy
from PySide6.QtGui import QShortcut, QKeySequence
import PySide6.QtCore as QtCore

#Utilisation d'un dico pour faciliter l'implementation des boutons

BUTTONS = {
            "C" : (1, 0, 1, 1 ), #fonctionnement du dico une information (ici du texte) associé à des valeurs (position y, position x, hauteur, largeur)
            "/" : (1, 3, 1, 1 ),
            "7" : (2, 0, 1, 1 ),
            "8" : (2, 1, 1, 1 ),
            "9" : (2, 2, 1, 1 ),
            "x" : (2, 3, 1, 1 ),
            "4" : (3, 0, 1, 1 ),
            "5" : (3, 1, 1, 1 ),
            "6" : (3, 2, 1, 1 ),
            "-" : (3, 3, 1, 1 ),
            "1" : (4, 0, 1, 1 ),
            "2" : (4, 1, 1, 1 ),
            "3" : (4, 2, 1, 1 ),
            "+" : (4, 3, 1, 1 ),
            "0" : (5, 0, 1, 2 ),
            "." : (5, 2, 1, 1 ),
            "=" : (5, 3, 1, 1 )
        }

OPERATIONS = {"+", "-", "/", "x"}

#fin du dico

class MainWindow(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("caclulator")
        self.setStyleSheet("background-color : rgb(20, 20, 20); color : rgb(220, 220, 220); font-size : 18px")

        self.GridLayOut = QGridLayout(self)
        self.GridLayOut.setSpacing(0)
        self.GridLayOut.setContentsMargins(0,0,0,0)

        self.stock_buttons = {}
        
        self.le_result = QLineEdit()
        self.le_result.setMinimumHeight(50)
        self.le_result.setAlignment(QtCore.Qt.AlignCenter)
        self.le_result.setPlaceholderText("On calcul ?")
        self.le_result.setEnabled(False)
        self.le_result.setStyleSheet("border: none; font-size : 24px; font-weight : bold; padding : 0 8px; border-bottom: 2px solid rgb(30, 30, 30);")
        
        self.GridLayOut.addWidget(self.le_result, 0, 0, 1, 4)

        for button_text, button_value in BUTTONS.items() :
            button = QPushButton(button_text)
            button.setMinimumSize(48,48)
            button.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)
            button.setStyleSheet(f"QPushButton {{border: none; font-weight: bold; background-color : {'#1e1e2d' if button_text in OPERATIONS else 'none'}}} QPushButton:Pressed {{background-color : #f31d58;}}")
            self.GridLayOut.addWidget(button, *button_value)
            if button_text not in ["=", "C"] :
                button.clicked.connect(self.number_or_operation_pressed)
            # cette * devant button_value permet d'unpacker les coordonnees du dico et de ne pas ecrire button_value[0], etc.
            self.stock_buttons[button_text] = button
        
        self.stock_buttons["C"].clicked.connect(self.le_result.clear)
        self.stock_buttons["="].clicked.connect(self.compute_result)
        self.stock_buttons["="].setStyleSheet("background-color : #f31d58;")
        

        self.connect_keyboard_shortcut()

    @property
    def result (self) :
        return self.le_result.text()
    
    #property permet de définir une méthode pour rendre plus lisible le code

    def compute_result (self):
        try:
            result = eval(self.result.replace("X","*"))
            self.le_result.setText(str(result))
        except SyntaxError:
            return

    def number_or_operation_pressed (self):
        if self.sender().text() in OPERATIONS :
            if self.result == "" or self.result[-1] ==  self.sender().text():
                return
            elif self.result[-1] in OPERATIONS :
                self.le_result.setText(self.result[:-1] + self.sender().text())
                return
                
        
        self.le_result.setText(self.result + self.sender().text())

    def connect_keyboard_shortcut (self):
        for button_text, button in self.stock_buttons.items():
            QShortcut(QKeySequence(button_text), self, button.clicked.emit) # le .emit permet d'emuler l'appui sur un bouton
        QShortcut(QKeySequence(QtCore.Qt.Key_Return), self, self.compute_result)
        QShortcut(QKeySequence(QtCore.Qt.Key_Backspace), self, self.remove_last_caracter)

    def remove_last_caracter (self):
        self.le_result.setText(self.result[:-1])





app = QApplication() #Instancie l'application du programme dans app
#win = QWidget() #Instancie une fenetre pour l'application dans win
#win.show() #Permet d'afficherr la fenetre

main_window = MainWindow()
main_window.show()
app.exec() #Lance l'application