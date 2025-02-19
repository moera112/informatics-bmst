letters = ' '.join('АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ'.lower()).split()

print("\tВведите 1 если хотите зашифровать сообщение\n\tВведите 2 если хотите расшифровать сообщение\n\tВвод: ", end = '')

if(int(input()) == 1):
    print("\tВведите строку: ", end = '')
    st = input()
    print('\n\t Введите шаг шифра: ', end = '')
    walk = int(input())
    ready_string = ''
    for i in st.lower():
        if i.isalpha():
            ind = letters.index(i) + walk if letters.index(i) + 8 < len(letters) - 1 else letters.index(i) + walk - (len(letters) - 1) - 1
            ready_string += letters[ind]
            continue
        ready_string += i
    print(ready_string)
else:
    print("\tВведите строку: ", end = '')
    st = input()
    print('\n\t Введите шаг шифра: ', end = '')
    walk = int(input())
    ready_string = ''
    for i in st.lower():
        if i.isalpha():
            ind = letters.index(i) - walk if letters.index(i) - walk >= 0 else len(letters) - 1 - abs(letters.index(i) - walk) + 1
            ready_string += letters[ind]
            continue
        ready_string += i
    print(ready_string)
