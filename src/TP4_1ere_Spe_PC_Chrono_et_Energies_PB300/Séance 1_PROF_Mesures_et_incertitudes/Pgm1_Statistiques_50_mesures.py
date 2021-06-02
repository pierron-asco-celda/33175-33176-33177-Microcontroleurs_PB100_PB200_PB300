# Programme réalisé par Patrice BUFFET professeur de Physique-Chimie

from matplotlib.pyplot import *
from numpy import mean, std     # utile pour l'ecart type et la valeur moyenne
from math import sqrt

# Liste des mesures de résistance
ListeMes = [603,616,606,626,622,605,601,631,610,634,636,629,621,634,611,627,632,626,618,617,630,626,612,620,607,609,622,624,612,619,624,616,600,618,615,627,616,610,599,617,629,601,611,611,608,622,618,616,619,600]

# fonction sur les listes

print("La valeur minimale est de",min(ListeMes),"ms")
print("La valeur maximale est de",max(ListeMes),"ms")

# fonction du module statistiques numpy
# http://python-simple.com/python-numpy-scipy/statistics-numpy.php

ValMoy=mean(ListeMes)       # Mean  = moyenne, module numpy nécessaire
Ecart_type=std(ListeMes)    # std = standard deviation = écart type, module numpy nécessaire
NbreMes=len(ListeMes)
incertA=round(Ecart_type/sqrt(NbreMes),1) # incertitude de type A, résultat avec un chiffre après la virgule
# round(valeur,N), fonction arrondir avec N chiffres après la virgule

# Affichage des résultats dans la console
print("La valeur moyenne est de",round(ValMoy,1),"ms")
print("L'écart type expérimental est de",round(Ecart_type,1),"ms")
print("L'incertitude de type A est de",incertA,"ms")


hist(ListeMes,range=(min(ListeMes),max(ListeMes)),bins=(max(ListeMes)-min(ListeMes)+1), color = 'yellow',edgecolor = 'red',)
"""
hist(liste de valeurs, + options avec mots clés)
    range = (valeur min, valeur max)
    bins = nombre d'intervalles
    color = couleur des barres
    edgecolor = couleur du contour des barres
    plus d'options sur
    http://python-simple.com/python-matplotlib/histogram.php
"""

NbEch=str(len(ListeMes))
xlabel("durée du parcours (en ms)")
ylabel("effectifs")
title("Objet = voiture ; Dénivelé h = 30 cm ; "+NbEch+" échantillons")
# l'opération +, ci dessus, permet de concaténer les chaines de caractères
show()
