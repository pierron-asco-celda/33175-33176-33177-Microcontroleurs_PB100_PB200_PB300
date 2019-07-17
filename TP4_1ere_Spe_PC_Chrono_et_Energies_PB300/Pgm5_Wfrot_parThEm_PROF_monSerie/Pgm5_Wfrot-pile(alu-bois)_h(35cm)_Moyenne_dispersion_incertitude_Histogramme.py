from matplotlib.pyplot import *
from numpy import mean, std     # utile pour l'ecart type et la valeur moyenne
from math import sqrt

# Liste des mesures de résistance
ListeMes = [155, 159, 148, 152, 154, 154, 156, 154, 159, 152, 159, 153, 151, 151, 153, 153, 157, 155, 155, 158]

# fonction sur les listes

print("La valeur minimale est de",min(ListeMes),"mJ")
print("La valeur maximale est de",max(ListeMes),"mJ")

# fonction du module statistiques numpy
# http://python-simple.com/python-numpy-scipy/statistics-numpy.php

ValMoy=mean(ListeMes)       # Mean  = moyenne, module numpy nécessaire
Ecart_type=std(ListeMes)    # std = standard deviation = écart type, module numpy nécessaire
NbreMes=len(ListeMes)
incertA=round(Ecart_type/sqrt(NbreMes),1) # incertitude de type A, résultat avec un chiffre après la virgule
# round(valeur,N), fonction arrondir avec N chiffres après la virgule

# Affichage des résultats dans la console
print("La valeur moyenne est de",round(ValMoy,1),"mJ")
print("L'écart type expérimental est de",round(Ecart_type,1),"mJ")
print("L'incertitude de type A est de",incertA,"mJ")


hist(ListeMes,range=(min(ListeMes),max(ListeMes)),bins=(max(ListeMes)-min(ListeMes)), color = 'yellow',edgecolor = 'red',)
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
xlabel("Valeur absolue du W des forces de frottement (en mJ)")
ylabel("occurences")
title("Objet = pile (face bois); Dénivelé h = 35 cm; "+NbEch+" échantillons")
# l'opération +, ci dessus, permet de concaténer les chaines de caractères
show()
