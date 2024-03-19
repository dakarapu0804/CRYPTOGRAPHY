def otp_vigenere_encrypt(plain_text, key):
    encrypted_text = ""
    
    for i in range(len(plain_text)):
        if plain_text[i].isalpha():
            char_code = ord('a')
            encrypted_text += chr(char_code + (ord(plain_text[i]) - char_code + key[i]) % 26)
        else:
            encrypted_text += plain_text[i]
            
    return encrypted_text

plain_text = "sendmoremoney"
key_stream = [9, 0, 1, 7, 23, 15, 21, 14, 11, 11, 2, 8, 9]
encrypted_text = otp_vigenere_encrypt(plain_text, key_stream)

print("Encrypted:", encrypted_text)
def find_key_for_plaintext(ciphertext, desired_plaintext):
    key = []
    for i in range(len(ciphertext)):
        if ciphertext[i].isalpha():
            char_code = ord('a')
            shift = (ord(ciphertext[i]) - ord(desired_plaintext[i])) % 26
            key.append(shift)
        else:
            key.append(0)  # just a placeholder for spaces or other non-alphabetic chars
            
    return key

desired_plaintext = "cashnotneeded"
key_for_desired_plaintext = find_key_for_plaintext(encrypted_text, desired_plaintext)

print("Key for desired plaintext:", key_for_desired_plaintext)
