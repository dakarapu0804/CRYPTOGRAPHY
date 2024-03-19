def generate_playfair_matrix(key):
    key = key.replace("J", "I")  
    key = key.upper()
    key = "".join(dict.fromkeys(key))  
    alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ"
    
    matrix = [[0] * 5 for _ in range(5)]
    key_index = 0
    alphabet_index = 0
    
    for i in range(5):
        for j in range(5):
            if key_index < len(key):
                matrix[i][j] = key[key_index]
                key_index += 1
            else:
                while alphabet[alphabet_index] in key:
                    alphabet_index += 1
                matrix[i][j] = alphabet[alphabet_index]
                alphabet_index += 1
    
    return matrix

def find_position(matrix, letter):
    for i in range(5):
        for j in range(5):
            if matrix[i][j] == letter:
                return i, j

def playfair_encrypt(matrix, plaintext):
    plaintext = plaintext.replace("J", "I")  
    plaintext = plaintext.upper()
    plaintext = plaintext.replace(" ", "")  
    
    if len(plaintext) % 2 == 1:
        plaintext += "X"  # Pad with 'X' if odd length
    
    encrypted_text = ""
    for i in range(0, len(plaintext), 2):
        char1 = plaintext[i]
        char2 = plaintext[i+1]
        
        row1, col1 = find_position(matrix, char1)
        row2, col2 = find_position(matrix, char2)
        
        if row1 == row2:
            encrypted_text += matrix[row1][(col1 + 1) % 5] + matrix[row2][(col2 + 1) % 5]
        elif col1 == col2:
            encrypted_text += matrix[(row1 + 1) % 5][col1] + matrix[(row2 + 1) % 5][col2]
        else:
            encrypted_text += matrix[row1][col2] + matrix[row2][col1]
    
    return encrypted_text

def main():
    key = input("Enter the keyword: ")
    plaintext = input("Enter the plaintext: ")

    matrix = generate_playfair_matrix(key)
    encrypted_text = playfair_encrypt(matrix, plaintext)
    
    print("Playfair Matrix:")
    for row in matrix:
        print(" ".join(row))
    
    print("Encrypted Text:", encrypted_text)

if __name__ == "__main__":
    main()
