Voici l'architecture du projet.

+---build // R�pertoire de construction de la dll pour les diff�rents OS
�   +---linux
�   +---mac
�   �   +---JuceDemoPlugin.xcodeproj
�   +---win32
�       +---Debug
�       +---Release // ici se trouvera la dll (redverb.dll)
�       +---_UpgradeReport_Files
+---src // ici se trouvent les sources � modifier
    +---juce // ici se trouvent les sources de juce

Pour l'instant, on bosse avec VS2008 Pro. Le .sln marche out of the box
chez moi.

