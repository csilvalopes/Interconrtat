from functools import partial

from PySide2 import QtMultimedia, QtMultimediaWidgets, QtWidgets, QtCore
from PySide2.QtWidgets import QApplication


class MainWindow(QtWidgets.QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("PyPlayer")
        

        self.open_icon = self.style().standardIcon(QtWidgets.QStyle.SP_DriveDVDIcon)
        self.play_icon = self.style().standardIcon(QtWidgets.QStyle.SP_MediaPlay)
        self.pause_icon = self.style().standardIcon(QtWidgets.QStyle.SP_MediaPause)
        self.previous_icon = self.style().standardIcon(QtWidgets.QStyle.SP_MediaSkipBackward)
        self.stop_icon = self.style().standardIcon(QtWidgets.QStyle.SP_MediaStop)
        self.setup_ui()

    def setup_ui (self):
            self.create_widgets()
            self.create_layouts()
            self.modify_widgets()
            self.add_widgets_to_layouts()
            self.setup_connections()

    def create_widgets (self) :
        self.video_widget = QtMultimediaWidgets.QVideoWidget()
        self.player = QtMultimedia.QMediaPlayer()
        self.toolbar = QtWidgets.QToolBar()
        self.file_menu = self.menuBar().addMenu("Fichier")

        #Actions
        self.act_open = self.file_menu.addAction(self.open_icon, "Ouvrir")
        self.act_open.setShortcut("Ctrl+O")
        self.act_play = self.toolbar.addAction(self.play_icon, "Lire")
        self.act_previous = self.toolbar.addAction(self.previous_icon, "Revenir au debut")
        self.act_pause = self.toolbar.addAction(self.pause_icon, "Pause")
        self.act_stop = self.toolbar.addAction(self.stop_icon, "Stop")

    def modify_widgets (self) :
        pass

    def create_layouts (self) :
        pass

    def add_widgets_to_layouts (self) :
        self.addToolBar(self.toolbar)
        self.setCentralWidget(self.video_widget)
        self.player.setVideoOutput(self.video_widget)

    def setup_connections (self) :
        self.act_open.triggered.connect(self.open)
        self.act_play.triggered.connect(self.play)
        self.act_pause.triggered.connect(self.player.pause)
        self.act_stop.triggered.connect(self.player.stop)
        self.act_previous.triggered.connect(partial(self.player.setPosition, 0))
        self.player.stateChanged.connect(self.update_buttons)

    def play (self):
        self.player.play()
        self.video_widget.resize(QtCore.QSize(1,1))

    def open (self):
        file_dialog = QtWidgets.QFileDialog(self)
        file_dialog.setMimeTypeFilters(["video/mp4"])
        movies_dir = QtCore.QStandardPaths.writableLocation(QtCore.QStandardPaths.MoviesLocation)
        file_dialog.setDirectory(movies_dir)
        if file_dialog.exec() == QtWidgets.QDialog.Accepted:
            movie = file_dialog.selectedUrls()[0]
            self.player.setMedia(movie)
            self.player.play()

    def update_buttons (self, state):
        self.act_play.setDisabled(state == QtMultimedia.QMediaPlayer.PlayingState)
        self.act_pause.setDisabled(state == QtMultimedia.QMediaPlayer.PausedState)
        self.act_stop.setDisabled(state == QtMultimedia.QMediaPlayer.StoppedState)

if __name__ == '__main__':
    app = QApplication() 
    window = MainWindow()
    window.resize(1920 / 2, 1200 / 2)
    window.show()
    app.exec_()