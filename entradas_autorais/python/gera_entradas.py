import random
import names
import pandas
from faker import Faker
fake = Faker('pt_BR')


def gera_usuarios(n):
    tipos = ['A', 'P', 'U']
    with open("usuarios_python.csv", "w+", encoding="utf8") as file:
        file.write("Codigo;Tipo;Nome\n")
        for i in range(1, n + 1):
            file.write(f"{i};{random.choice(tipos)};{names.get_full_name()}\n")
    pass


def gera_generos(n):
    with open("genres.txt", "r", encoding="utf8") as fG:
        genres = [line.strip().capitalize() for line in fG]

    with open("generos_python.csv", "w+", encoding="utf8") as file:
        file.write("Sigla;Nome\n")
        for i in range(n):
            genero = random.choice(genres)
            genres.remove(genero)
            if len(genero.split()) > 1:
                sigla = f"{genero.split()[0][0]}{genero.split()[1][0]}".upper()
            else:
                sigla = f"{genero[0]}{genero[1]}".upper()
            file.write(f"{sigla};{genero}\n")
    pass


def gera_midias(n, arquivoGeneros, arquivoUsuarios):
    with open("midias_python.csv", "w+", encoding="utf8") as file:
        file.write("Código;Nome;Tipo;Produtores;Duração;Gênero;Temporada;Álbum;Publicação\n")

        generoCSV = pandas.read_csv(f"{arquivoGeneros}", sep=';')
        generoCSV = generoCSV["Sigla"].tolist()

        usuariosCSV = pandas.read_csv(f"{arquivoUsuarios}", sep=";")
        tipoUsuario = usuariosCSV["Tipo"].tolist()
        nomeUsuario = usuariosCSV["Nome"].tolist()

        nMidias = range(1, n + 1)
        for i in nMidias:
            file.write(f"{i};")
            nomeMidia = fake.catch_phrase()
            publicacaoMidia = random.randint(1990, 2077)
            tipoMidia = random.choice(['M', 'P'])

            produtores = list()

            if tipoMidia is 'M':
                duracaoMidia = round(random.uniform(1, 10), 2)
                temporadaMidia = ''
                albumMidia = fake.catch_phrase()
                while len(produtores) < random.randint(1, 3):
                    randProd = random.randint(0, n / 2 - 1)
                    if tipoUsuario[randProd] is "A":
                        produtores.append(randProd + 1)
            else:
                duracaoMidia = round(random.uniform(1, 120), 2)
                temporadaMidia = random.randint(1, 20)
                albumMidia = ''
                while len(produtores) < random.randint(1, 3):
                    randProd = random.randint(0, n / 2 - 1)
                    if tipoUsuario[randProd] is "P":
                        produtores.append(randProd + 1)

            genero = random.choice(generoCSV)

            file.write(f"{nomeMidia};{tipoMidia};")
            for produtor in produtores:
                if produtor != produtores[-1]:
                    file.write(f"{produtor}, ")
                else:
                    file.write(f"{produtor};")
            file.write(f"{duracaoMidia};{genero};{temporadaMidia};{albumMidia};{publicacaoMidia}")
            file.write("\n")
    pass


def gera_favoritos(n):
    with open("favoritos_python.csv", "w+", encoding="utf8") as file:
        file.write("Codigo;Midias Favoritas\n")
        for i in range(1, n + 1):
            file.write(f"{i};")
            nMidias = range(random.randrange(n / 5))
            for f in nMidias:
                if f != nMidias[-1]:
                    file.write(f"{random.randrange(1, n)},")
                else:
                    file.write(f"{random.randrange(1, n)}")
            file.write("\n")
    pass


gera_favoritos(200)
gera_usuarios(200)
gera_generos(200)
gera_midias(200, "generos_python.csv", "usuarios_python.csv")
