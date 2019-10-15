import random
import names
import pandas
from faker import Faker
fake = Faker('pt_BR')


def gera_usuarios(nUsuarios):
    tipos = ['A', 'P', 'U']
    with open("usuarios_python.csv", "w+", encoding="utf8") as file:
        file.write("Código;Tipo;Nome\n")
        for i in range(1, nUsuarios + 1):
            file.write(f"{i};{random.choice(tipos)};{names.get_full_name()}\n")
    pass


def gera_generos(nGeneros):
    with open("genres.txt", "r", encoding="utf8") as fG:
        genres = [line.strip().capitalize() for line in fG]

    with open("generos_python.csv", "w+", encoding="utf8") as file:
        file.write("Sigla;Nome\n")
        for i in range(nGeneros):
            genero = random.choice(genres)
            genres.remove(genero)
            if len(genero.split()) > 1:
                sigla = f"{genero.split()[0][0]}{genero.split()[1][0]}".upper()
            else:
                sigla = f"{genero[0]}{genero[1]}".upper()
            file.write(f"{sigla};{genero}\n")
    pass


def gera_midias(nMidias, arquivoGeneros, arquivoUsuarios):
    with open("midias_python.csv", "w+", encoding="utf8") as file:
        file.write("Código;Nome;Tipo;Produtores;Duração;Gênero;Temporada;Álbum;Publicação\n")

        generoCSV = pandas.read_csv(f"{arquivoGeneros}", sep=';')
        generoCSV = generoCSV["Sigla"].tolist()

        usuariosCSV = pandas.read_csv(f"{arquivoUsuarios}", sep=";")
        tipoUsuario = usuariosCSV["Tipo"].tolist()
        nomeUsuario = usuariosCSV["Nome"].tolist()

        rangeMidias = range(1, nMidias + 1)
        for i in rangeMidias:
            file.write(f"{i};")
            nomeMidia = fake.catch_phrase()
            publicacaoMidia = random.randint(1990, 2077)
            tipoMidia = random.choice(['M', 'P'])

            produtores = list()

            if tipoMidia is 'M':
                duracaoMidia = f"{random.randint(1, 10)},{random.randint(0,99)}"
                temporadaMidia = ''
                albumMidia = fake.catch_phrase()
                while len(produtores) < random.randint(1, 3):
                    randProd = random.randint(1, nUsuarios - 1)
                    if tipoUsuario[randProd] is "A":
                        produtores.append(randProd + 1)
            else:
                duracaoMidia = duracaoMidia = f"{random.randint(1, 120)},{random.randint(0,99)}"
                temporadaMidia = random.randint(1, 20)
                albumMidia = ''
                while len(produtores) < random.randint(1, 3):
                    randProd = random.randint(1, nUsuarios - 1)
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


def gera_favoritos(nFavoritos, nMidias):
    with open("favoritos_python.csv", "w+", encoding="utf8") as file:
        file.write("Código;Mídias Favoritas\n")
        for i in range(1, nFavoritos + 1):
            file.write(f"{i};")
            rangeMidias = range(random.randrange(0, 20))
            for f in rangeMidias:
                if f != rangeMidias[-1]:
                    file.write(f"{random.randrange(1, nMidias)},")
                else:
                    file.write(f"{random.randrange(1, nMidias)}")
            file.write("\n")
    pass

# Editar valores aqui
nUsuarios = 100
nFavoritos = nUsuarios
nMidias = 500
nGeneros = 30

gera_favoritos(nFavoritos, nMidias)
gera_usuarios(nUsuarios)
gera_generos(nGeneros)
gera_midias(nMidias, "generos_python.csv", "usuarios_python.csv")
