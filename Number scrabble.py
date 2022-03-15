list_of_numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9]
sum1 = 0
sum2 = 0


# -------------- explain the game to the players -----------

def explain():
    print("Number scrabble is played with the list of numbers between 1 and 9.\n"
          "Each player takes turns picking a number from the list.\n"
          "Once a number has been picked, it cannot be picked again.\n"
          "If a player has picked three numbers that add up to 15, that player wins the game.\n"
          "However, if all the numbers are used and no player gets exactly 15, the game is a draw.\n")


# -------------- display remaining numbers ---------------

def display_state():
    global list_of_numbers
    print("choose number form ", list_of_numbers)


# ---------------- Get input and save the score -------------------

def get_input_1st():
    check1 = False
    global sum1
    while not check1:
        picked1 = input("First player please enter the number you want to pick : ")

        if picked1.isdigit:
            picked1 = int(picked1)
            if picked1 in list_of_numbers:
                check1 = True
                sum1 += picked1
            else:
                print("***Check if the number is available in the list ,please*** \n")
    return picked1


def get_input_2nd():
    check2 = False
    global sum2
    while not check2:
        picked2 = input("Second player please enter the number you want to pick : ")

        if picked2.isdigit:
            picked2 = int(picked2)
            if picked2 in list_of_numbers:
                check2 = True
                sum2 += picked2
            else:
                print("***Check if the number is available in the list ,please*** \n")
    return picked2


# --------------- update the list ------------------------

def update_state(number_picked):
    list_of_numbers.remove(number_picked)


# ---------------- display the score -----------------------

def display_score():
    print("First player have : ", sum1)
    print("Second player have : ", sum2)


# ------------------who is the winner ?---------------------

def first_won():
    if sum1 == 15:
        return True


def second_won():
    if sum2 == 15:
        return True


# ------------------ Enjoy playing <3 ---------------------

def play():
    explain()
    while len(list_of_numbers) != 0:
        display_state()
        if len(list_of_numbers) != 0:
            update_state(get_input_1st())
        display_score()
        if first_won():
            print("First player won <3")
            break
        display_state()
        if len(list_of_numbers) != 0:
            update_state(get_input_2nd())
        display_score()
        if second_won():
            print("Second player won <3")
            break
        if sum1 != 15 and sum2 != 15 and len(list_of_numbers) == 0:
            print("Draw")
            break


play()
