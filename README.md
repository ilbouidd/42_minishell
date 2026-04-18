*This project has been created as part of the 42 curriculum by ilbouidd*

# Minishell

## Description

## Instructions

## Resources

### Lecture de ligne :
•readline : lit une ligne complète depuis le terminal. Elle gère l’édition de ligne, l’historique, et le comportement interactif.

•rl_clear_history : vide l’historique de readline.

•rl_on_new_line : indique à readline qu’on passe à une nouvelle ligne.

•rl_replace_line : remplace le contenu courant de la ligne en cours d’édition.

•rl_redisplay : rafraîchit l’affichage de la ligne.

•add_history : ajoute une ligne à l’historique de readline.

### Affichage et mémoire :
•printf : affiche du texte formaté.

•malloc : alloue de la mémoire.

•free : libère la mémoire allouée.

### Fichiers et I/O :
•write : écrit des données dans un fichier ou sur la sortie standard.

•access : vérifie les droits d’accès à un fichier.

•open : ouvre un fichier.

•close : ferme un descripteur de fichier.

•read : lit depuis un descripteur de fichier.

### Processus :
•fork : crée un nouveau processus.

•wait, waitpid, wait3, wait4 : attend la fin d’un processus fils.

•execve : remplace le processus courant par un autre programme.

•exit : termine le processus courant.

•kill : envoie un signal à un processus.

### Signaux :
•signal : définit un gestionnaire de signal simple.

•sigaction : définit un gestionnaire de signal plus propre et plus précis.

•sigemptyset : initialise un masque de signaux vide.

•sigaddset : ajoute un signal à un masque.

### Répertoires et chemins :
•getcwd : récupère le répertoire courant.

•chdir : change de répertoire courant.

•stat, lstat, fstat : récupèrent des infos sur un fichier.

•unlink : supprime un fichier.

•opendir : ouvre un répertoire.

•readdir : lit les entrées d’un répertoire.

•closedir : ferme un répertoire.

### Erreurs et infos système :
•strerror : retourne le message associé à une erreur.

•perror : affiche un message d’erreur système.

•isatty : vérifie si un descripteur est un terminal.

•ttyname : donne le nom du terminal associé.

•ttyslot : retourne l’emplacement du terminal dans la table système.

•ioctl : commande bas niveau sur un descripteur.

### Variables d’environnement et terminal :
•getenv : récupère la valeur d’une variable d’environnement.

•tcsetattr : modifie les attributs du terminal.

•tcgetattr : lit les attributs du terminal.

•tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs : fonctions de la bibliothèque terminal/termcap pour gérer l’affichage avancé du terminal.

