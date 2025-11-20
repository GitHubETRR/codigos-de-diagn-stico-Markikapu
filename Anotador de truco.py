puntos = {"nosotros": 0, "ellos": 0}

def bienvenida():
    print("========================================")
    print("| Estás en el Anotador de Truco de Kapu|")
    print("========================================\n")

def elegir_limite():
    limite = input("¿A cuántos van a jugar? (15 o 30): ")
    if limite not in ("15", "30"):
        print("Bueno, les tocó jugar a 15.\n")
        return 15
    return int(limite)

def preguntar_flor():
    usar = input("¿Quieren jugar con flor? (si/no): ").lower()
    if usar == "si":
        print("\nnaa, acá no querido\n")
    else:
        print("\nPerfecto, sin flor.\n")

def menu():
    print("\n--- ANOTADOR DE TRUCO ---")
    print("1. Sumar puntos")
    print("2. Mostrar puntaje")
    print("3. Reiniciar partida")
    print("4. Salir")
    return input("Opción: ")

def normalizar_equipo(equipo):
    equipo = equipo.lower().strip()
    if equipo == "n":
        return "nosotros"
    if equipo == "e":
        return "ellos"
    return equipo
    
def sumar_puntos(limite):
    equipo = input("¿Quién suma puntos? (nosotros / ellos): ").lower()

    if equipo not in puntos:
        print("Equipo inválido.")
        return False

    try:
        pts = int(input("¿Cuántos puntos sumaron?: "))
    except:
        print("Número inválido.")
        return False

    puntos[equipo] += pts
    print(f"Sumaste {pts} puntos a {equipo}. Total: {puntos[equipo]}")

    # chequeo de victoria
    if puntos[equipo] >= limite:
        print(f"\n¡¡{equipo.upper()} GANARON LA PARTIDA!!\n")
        puntos["nosotros"] = 0
        puntos["ellos"] = 0
        return True

    return False

def mostrar():
    print("\n--- PUNTAJE ---")
    print(f"Nosotros: {puntos['nosotros']}")
    print(f"Ellos: {puntos['ellos']}")

def reiniciar():
    puntos["nosotros"] = 0
    puntos["ellos"] = 0
    print("Puntaje reiniciado.\n")

# PROGRAMA PRINCIPAL
bienvenida()
limite = elegir_limite()
preguntar_flor()

while True:
    op = menu()

    if op == "1":
        sumar_puntos(limite)
    elif op == "2":
        mostrar()
    elif op == "3":
        reiniciar()
        limite = elegir_limite()
    elif op == "4":
        print("Chau capo <3")
        break
    else:
        print("Opción inválida.")
