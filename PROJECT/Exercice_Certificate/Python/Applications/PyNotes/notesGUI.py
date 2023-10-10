import PySide6.QtWidgets as QtWidgets
import PySide6.QtGui as QtGui
import PySide6.QtCore as QtCore



from PySide6.QtWidgets import QApplication, QWidget, QPushButton, QHBoxLayout, QVBoxLayout, QGridLayout, QLineEdit, QSizePolicy, QListWidget, QTextEdit
from PySide6.QtGui import QShortcut, QKeySequence

from API_NOTES.notes import Notes, get_notes


class MainWindow(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Prise de notes")
        self.setup_ui()

        self.populate_notes()

    def setup_ui (self):
            self.create_widgets()
            self.create_layouts()
            self.modify_widgets()
            self.add_widgets_to_layouts()
            self.setup_connections()

    def create_widgets (self) :
        self.btn_CreateNote = QPushButton("Creer une note")
        self.te_content = QTextEdit()
        self.list_notes = QListWidget()

    def modify_widgets (self) :
        self.btn_CreateNote.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Fixed)
        self.te_content.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)
        self.list_notes.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)

    def create_layouts (self) :
        self.main_layout = QGridLayout(self)

    def add_widgets_to_layouts (self) :
        self.main_layout.addWidget(self.btn_CreateNote, 0, 0, 1, 1)
        self.main_layout.addWidget(self.te_content, 0, 1, 2, 1)
        self.main_layout.addWidget(self.list_notes, 1, 0, 1, 1)

    def setup_connections (self) :
        self.btn_CreateNote.clicked.connect(self.create_note)
        self.te_content.textChanged.connect(self.save_note)
        self.list_notes.itemSelectionChanged.connect(self.populate_note_content)
        QShortcut(QKeySequence("BackSpace"), self.list_notes, self.delete_selected_note)

    #END UI

    def addNoteToListWidget (self, note):
        lw_item = QtWidgets.QListWidgetItem(note.title)
        lw_item.note = note
        self.list_notes.addItem(lw_item)


    def create_note (self) :
        titre, resultat = QtWidgets.QInputDialog.getText(self, "Ajouter une note", "Titre de la note:")
        if resultat and titre :
            note = Notes(title=titre)
            note.save()
            self.addNoteToListWidget(note)
    
    def delete_selected_note (self) :
        selected_item = self.getCurrentNote()
        resultat = selected_item.note.delete()

        if resultat :
            self.list_notes.takeItem(self.list_notes.row(selected_item))
    

    def getCurrentNote (self):
        selected_items = self.list_notes.selectedItems()
        if not selected_items :
            return None
        
        return selected_items[0]

    def populate_notes (self) :
        notes = get_notes()
        for note in notes:
           self.addNoteToListWidget(note) 
    
    def populate_note_content (self) :
         selected_item = self.getCurrentNote()
         if selected_item:
             self.te_content.setText(selected_item.note.content)
         else :
             self.te_content.clear()
    
    def save_note (self) :
        selected_item = self.getCurrentNote()
        if selected_item :
            selected_item.note.content = (self.te_content.toPlainText())
            selected_item.note.save()
    




app = QApplication() #Instancie l'application du programme dans app
#win = QWidget() #Instancie une fenetre pour l'application dans win
#win.show() #Permet d'afficherr la fenetre

main_window = MainWindow()
main_window.show()
app.exec() #Lance l'application