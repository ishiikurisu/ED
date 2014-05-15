def prime (start, finish):
  if start < 2:
    start = 2
  if finish > start and start >= 2:
    i = start
    while i <= finish:
      j = 2
      cont = 0
      while j < i:
        if i % j == 0:
          cont += 1
          break
        j += 1
      if cont == 0:
        print(i)
      i += 1
  else:
    print("ERROR\n")

#a = raw_input("Start:\t")
#b = raw_input("End:\t")
a = 2
b = 519
prime(a, b)
input("\nPRESS ENTER TO CONTINUE")

