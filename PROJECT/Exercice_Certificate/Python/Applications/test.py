from PySide6.QtWidgets import QApplication, QWidget

app = QApplication() #Instancie l'application du programme dans app
win = QWidget() #Instancie une fenetre pour l'application dans win
win.show() #Permet d'afficherr la fenetre
app.exec() #Lance l'application