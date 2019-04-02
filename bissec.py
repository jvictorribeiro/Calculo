#Metodo da bisseccao em python

def f(x):
    return x*x*x*x*x - 10/9*x*x*x + 5/21*x

# Printa a raiz aproximada de f(x) com erro epsilon
def bisection(a, b):
    if(f(a) * f(b) >= 0):
        print("Os valores de a e b estão incorretos\n")
        return

    c = a
    # enquanto for maior que o erro faz a iteraçao
    while((b - a) >= 0.00001):

        #Encontra o valor mediano
        c = (a + b) / 2

        #Verifica se o valor mediano eh raiz
        if(f(c) == 0.0):
            break

        print("O valor de a eh : ", "%.6f" % a)
        print("O valor de b eh : ", "%.6f" % b)

        # Decide o lado para repetir os passos anteriores
        if(f(c) * f(a) < 0):
            b = c
        else:
            a = c

        print("O valor da raiz eh : ", "%.6f" % c)
        print("O valor de f(cn) : ", "%.6f" % f(c))

    print("O valor final da raiz eh : ", "%.6f" % c)

# main
# Valores iniciais assumidos
a = -0.75
b = -0.25
bisection(a, b)

