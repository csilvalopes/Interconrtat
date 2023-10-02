from PySide6.QtWidgets import QApplication, QWidget, QVBoxLayout, QHBoxLayout, QPushButton, QLineEdit, QListWidget, QLabel
from functools import partial

class MainWindow(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("To Do List")

        self._btn = QPushButton("Clear All")
        self._le = QLineEdit()
        self.Initialize_le()
        self._list = QListWidget()

        main_layout = QVBoxLayout(self)
        main_layout.addWidget(self._list)
        main_layout.addWidget(self._le)
        main_layout.addWidget(self._btn)

        self._le.returnPressed.connect(self.PasteMyMessage)
        self._btn.clicked.connect(self.clearAll)
        self._list.itemDoubleClicked.connect(self.delete_item)

    def Initialize_le (self):
        self._le.clear()
        self._le.setPlaceholderText("Tâche à effectuer") 

    def PasteMyMessage (self):
        self._list.addItem(self._le.text())
        self.Initialize_le()
    
    def clearAll (self):
        self._list.clear()
        self.Initialize_le()
    
    def delete_item (self, item):
        self._list.takeItem(self._list.row(item))
        #takeItem permet de prendre l'element de la list qui lui est transmis en parametre
        #row permet de connaitre la position  de l'item fournis en parametre dans la list



app = QApplication() #Instancie l'application du programme dans app

main_window = MainWindow()
main_window.show()
app.exec() #Lance l'application