//Sliding Window Technique
def plus_petite_sequence(nbJours, nbGroupes, sequence):
    # Dictionnaire pour garder le compte des groupes dans la fenêtre actuelle
    groupe_count = {}
    # Nombre total de groupes distincts trouvés dans la fenêtre actuelle
    distinct_count = 0
    # Pointeur pour le début de la fenêtre
    start = 0
    # Longueur minimale trouvée, on commence par une valeur inférieure maximale possible
    min_length = nbJours + 1
    
    for end in range(nbJours):
        groupe = sequence[end]
        
        if groupe not in groupe_count:
            groupe_count[groupe] = 0
        
        # Si c'est la première fois qu'on voit ce groupe dans la fenêtre actuelle
        if groupe_count[groupe] == 0:
            distinct_count += 1
        
        groupe_count[groupe] += 1
        
        # Si tous les groupes sont couverts dans la fenêtre actuelle
        while distinct_count == nbGroupes:
            # Mettre à jour la longueur minimale
            min_length = min(min_length, end - start + 1)
            
            # Réduire la fenêtre en déplaçant le pointeur `start`
            groupe_start = sequence[start]
            groupe_count[groupe_start] -= 1
            if groupe_count[groupe_start] == 0:
                distinct_count -= 1
            start += 1
    
    return min_length

# Lecture des entrées
nbJours, nbGroupes = map(int, input().split())
sequence = list(map(int, input().split()))

# Calcul et affichage de la réponse
print(plus_petite_sequence(nbJours, nbGroupes, sequence))
