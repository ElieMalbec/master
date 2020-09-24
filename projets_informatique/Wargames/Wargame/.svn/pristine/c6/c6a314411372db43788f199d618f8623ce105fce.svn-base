# -*- coding: utf-8 -*-
"""Lancement du programme par le fichier main. L'interface est lancée par défaut dans une boucle mainloop"""
import time  # Pour execution time
from tkinter import Image

import interface

start_time = time.time()

# Lancement de la boucle principale de l'interface graphique
if __name__ == "__main__":
    """Boucle de lancement de l'application"""
    app = interface.MaFen()
    img = Image("photo", file="Images/icon.png")
    app.tk.call('wm', 'iconphoto', app._w, img)
    app.mainloop()

print("Process Finished\nExecution time : ")
print("--- %s seconds ---" % (time.time() - start_time))
del start_time
