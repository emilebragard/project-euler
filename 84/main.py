import time, random

start_time = time.time()

simuls = 10**6
distr = [0 for _ in range(40)]

def land_on_sqaure(curSquare, cc_deck, cc_cur, chance_deck, chance_cur):
    if curSquare == 30:
        curSquare = 10

    if curSquare in [2, 17, 33]:
        if cc_deck[cc_cur] != None:
            curSquare = cc_deck[cc_cur]
        cc_cur = (cc_cur + 1) % 16

    if curSquare in [7, 22, 36]:
        card = chance_deck[chance_cur]
        chance_cur = (chance_cur + 1) % 16
        if card != None: 
            if card == 'R':
                curSquare = (curSquare // 10) * 10 + 5
            elif card == 'B3':
                curSquare = land_on_sqaure(curSquare-3, cc_deck, cc_cur, chance_deck, chance_cur)[0]
            elif card == 'U':
                if curSquare == 22:
                    curSquare = 28
                else:
                    curSquare = 12
            else:
                curSquare = card
        
    
    return curSquare, cc_cur, chance_cur


# Prepare the Community Chest Deck
cc_deck = [0, 10] + [ None for _ in range(14)]  
cc_cur = 0

# Prepare the Chance Deck
chance_deck = [0, 10, 11, 24, 39, 5, 'R', 'R', 'U', 'B3'] + [None for _ in range(6)]
chance_cur = 0

consec_rolls = 0
square = 0
for _ in range(simuls):
    die1 = random.randint(1,4)
    die2 = random.randint(1,4)

    if die1 == die2:
        consec_rolls +=1
        if consec_rolls == 3:
            distr[10] += 1
            consec_rolls = 0
            square = 10
            continue
    else:
        consec_rolls = 0
    
    nextSquare = (square + die1 + die2) % 40
    square, cc_cur, chance_cur = land_on_sqaure(nextSquare, cc_deck, cc_cur, chance_deck, chance_cur)
    
    distr[square] += 1

while any(distr):
    maxN = max(distr)
    maxIdx = distr.index(maxN)
    print(maxIdx, end=" ")
    distr[maxIdx] = 0

end_time = time.time()

print("\nelapsed time: ", end_time - start_time, " seconds")