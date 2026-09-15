import csv

encrypted_string = []
with open('0059_cipher.txt', newline='') as csvfile:
    csv_reader = csv.reader(csvfile, delimiter=',')
    for row in csv_reader:
        encrypted_string.append([int(num) for num in row])

encrypted_string = encrypted_string[0]

for i in range(97,123):
    for j in range(97,123):
        for k in range(97,123):
            new_string = []
            all_words = True
            char_freq = 0
            for a in range(len(encrypted_string)):
                if a % 3 == 0:
                    x = (encrypted_string[a] ^ i)
                    if (x < 32 or x > 122):
                        all_words = False
                        break
                    if (x < 32 or 32 < x < 65 or 90 < x < 97 or x > 122):
                        char_freq +=1
                    new_string.append(x)
                elif a % 3 == 1:
                    x = (encrypted_string[a] ^ j)
                    if (x < 32 or x > 122):
                        all_words = False
                        break
                    if (x < 32 or 32 < x < 65 or 90 < x < 97 or x > 122):
                        char_freq +=1
                    new_string.append(x)
                else:
                    x = (encrypted_string[a] ^ k)
                    if (x < 32 or x > 122):
                        all_words = False
                        break
                    if (x < 32 or 32 < x < 65 or 90 < x < 97 or x > 122):
                        char_freq +=1
                    new_string.append(x)
            
            if (all_words and char_freq < 200):
                decrypted_text = ''.join(chr(num) for num in new_string)
                print(decrypted_text)
                print(sum(new_string))

