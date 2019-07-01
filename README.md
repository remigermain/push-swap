# pushswap :heavy_check_mark:

Le programme “push_swap”

•Vous devez écrire un programme nommépush_swap qui prend en paramètre la
pile 'a' sous la forme d’une liste d’entiers.
Le premier paramètre est au sommetde la pile (attention donc à l’ordre).
Si aucun paramètre n’est passé,push_swaptermine immédiatement et n’affiche rien.

•Le programme doit afficher le programme composé de la plus petite suite
d’ins-tructions possible qui permet de trier la pilea, le plus petit nombre étant ausommet.

•Les instructions doivent être affichées separées par un ’\n’ et rien d’autre.

•Le but est de trier les entiers avec le moins d’opérations possibles.
En soutenance,nous comparerons le nombre d’instructions que votre programme a 
calculé avec unnombre d’opération maximum toléré. Si votre programme affiche un 
programmetrop long, ou si bien sûr ce programme ne trie pas la liste, vous 
n’aurez pas depoints pour ce test.

•En cas d’erreur, vous devez afficherErrorsuivi d’un ’\n’ sur lasortie d’erreur.
Par exemple si certains paramètres ne sont pas des nombres,
certains paramètresne tiennent pas dans unint, ou encore s’il y a des doublons.


•Vous devez écrire un programme nommécheckerqui prend en paramètre la pileasous
la forme d’une liste d’entiers. Le premier paramètre est au sommet de la 
pile (attention donc à l’ordre).

•Checkerdoit ensuite attendre de lire 
des instructions sur l’entrée standard, chaqueinstruction suivie par un ’\n’. 
Une fois toutes les instructions lues, le checker vaexécuter ces instructions 
sur la pile d’entiers passée en paramètres.

•Si après exécution la pileaest bien 
triée et la pilebest vide, alorscheckerdoitafficher"OK"suivi par un ’\n’ 
sur la sortie standard. Dans tous les autres cas,checkerdoit afficher"KO"suivi 
par un ’\n’ sur la sortie standard.

•En cas d’erreur, vous devez afficher
Errorsuivi d’un ’\n’ sur lasortie d’erreur.Par exemple si certains paramètres 
ne sont pas des nombres, certains paramètresne tiennent pas dans unint,
s’il y a des doublons, ou bien sûr si une instructionn’existe pas ou est mal formatée.




# Règles du jeu

•Le jeu est constitué de 2 piles nommées a et b.
•Au départ : a contient un nombre arbitraire d’entiers positifs ou négatifs, sans doublons.
Le but du jeu est de trieradans l’ordre croissant.

•Pour ce faire, on ne dispose que des opérations suivantes :
```
sa :swap a- intervertit les 2 premiers éléments au sommet de la pile a. Ne fait rien s’il n’y en a qu’un ou aucun.
sb :swap b- intervertit les 2 premiers éléments au sommet de la pile b. Ne fait rien s’il n’y en a qu’un ou aucun.
ss :sa et sb en même temps.

pa :push a- prend le premier élément au sommet de b et le met sur a. Ne fait rien si b est vide.
pb :push b- prend le premier élément au sommet de a et le met sur b. Ne fait rien si a est vide.

ra :rotate a- décale d’une position vers le haut tous les élements de la pile a.Le premier élément devient le dernier.
rb :rotate b- décale d’une position vers le haut tous les élements de la pile b.Le premier élément devient le dernier.
rr :ra et rb en même temps.

rra :reverse rotate a- décale d’une position vers le bas tous les élements de la pile a. Le dernier élément devient le premier.
rrb :reverse rotate b- décale d’une position vers le bas tous les élements de la pile b. Le dernier élément devient le premier.
rrr :rra et rrb en même temps
```

# usage

```
./checker [ Flags ] < Numbers >
    [ Flags ]
        -v      for visual
        -i      for interactive mod
```
