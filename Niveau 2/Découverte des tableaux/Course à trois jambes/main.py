nbParticipants = int(input())
nombre = [0] * nbParticipants
for loop in range(nbParticipants):
    nombre[loop] = int(input())
nombre.sort()
for loop in range(nbParticipants // 2):
    print("{} {}".format(nombre[loop], nombre[nbParticipants - loop - 1]))
