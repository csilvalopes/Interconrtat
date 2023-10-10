import os, json
from uuid import uuid4
from glob import glob

from API_NOTES.constantes import NOTES_DIR

def get_notes () :
    notes = []
    fichiers = glob(os.path.join(NOTES_DIR, "*.json"))
    for fichier in fichiers :
        with open(fichier, "r") as f:
            note_data = json.load(f)
            note_uuid = os.path.splitext(os.path.basename(fichier))[0]
            note_title = note_data.get("title")
            note_content = note_data.get("content")
            note = Notes(note_title, note_content, note_uuid)
            notes.append(note)
    return notes


class Notes:
    def __init__(self, title="", content="", uuid=None) -> None:
        if uuid :
            self.uuid = uuid 
        else:
            self.uuid = str(uuid4())
        self.title = title
        self.content = content

    def __repr__(self) -> str:
        return f"{self.title} ({self.uuid})"

    def __str__(self) -> str:
        return self.title
    
    
    @property
    def content(self):
        return self._content

    @content.setter
    def content (self, value):
        if isinstance(value, str):
            self._content=value
        else:
            raise TypeError("Valeur Invalide (besoin d'une chaine de caractere)")
        
    def delete (self):
        os.remove(self.path)
        if os.path.exists(self.path) :
            return False
        return True

    @property
    def path(self):
        return os.path.join(NOTES_DIR, self.uuid + ".json")
        
    def save (self):
        if not os.path.exists(NOTES_DIR):
            os.makedirs(NOTES_DIR)

        data = {"title" : self.title, "content" : self.content}
        with open(self.path, "w") as f:
            json.dump(data, f, indent=4)

    


if __name__ == '__main__':
    notes = get_notes()
    print (notes)