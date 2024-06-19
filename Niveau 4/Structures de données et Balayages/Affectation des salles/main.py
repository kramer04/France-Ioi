import sys
import heapq
def main():
    nbSalle, nbRepresentation = map(int, input().split())
    events = []
    index = 0
    for line in sys.stdin:
        debut, fin = map(int, line.split())
        events.append((debut, fin, index))
        index += 1
        if index >= nbRepresentation:
            break
    events.sort()
    free_rooms = [(0, i) for i in range(1, nbSalle + 1)]
    heapq.heapify(free_rooms)
    room_assignment = [0] * nbRepresentation
    for start, end, idx in events:
        # Vérifie si une salle est disponible pour la représentation
        salle_disponible = False
        for _, (end_time, _) in enumerate(free_rooms):
            if end_time <= start:
                assigned_room = heapq.heappop(free_rooms)[1]
                heapq.heappush(free_rooms, (end, assigned_room))
                room_assignment[idx] = assigned_room
                salle_disponible = True
                break
        if not salle_disponible:
            print("NON")
            return
    print("OUI")
    #print(" ".join(map(str, room_assignment)))
    print(*room_assignment)
if __name__ == "__main__":
    main()
