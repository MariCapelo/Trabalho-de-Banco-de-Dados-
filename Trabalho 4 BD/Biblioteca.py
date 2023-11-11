import pyodbc 
import pandas as pd

dados_conexao = "DRIVER={SQLite3 ODBC Driver};SERVER=localhost;DATABASE=BDtrabalho.db;Trusted_connection=yes"

conexao = pyodbc.connect(dados_conexao)
print("Deu certo ai :)")
cursor = conexao.cursor()

comando = f"""SELECT COUNT(*)
    FROM sqlite_master
    WHERE type='table'
    AND name = 'Biblioteca';"""

comando2 = f"""SELECT COUNT(*)
    FROM sqlite_master
    WHERE type='table'
    AND name = 'Pessoa';"""
    
comando3 = f"""SELECT COUNT(*)
    FROM sqlite_master
    WHERE type='table'
    AND name = 'Aluga_Livro';"""        
    
x = cursor.execute(comando).fetchone()[0]
y = cursor.execute(comando2).fetchone()[0]
z = cursor.execute(comando3).fetchone()[0]

if x == 0:
    criarB = """CREATE TABLE Biblioteca(id INTEGER PRIMARY KEY AUTOINCREMENT, nome TEXT, autor TEXT, stat TEXT)""" 
    cursor.execute(criarB) 
    cursor.commit
    print("Tabela Biblioteca criada")
 
if y == 0: 
    criarP = """ CREATE TABLE Pessoa(cpf INTEGER PRIMARY KEY AUTOINCREMENT, nome TEXT, telefone INT)"""
    cursor.execute(criarP) 
    cursor.commit
    print("Tabela Pessoa criada")
    
if z == 0: 
    criarAG = """CREATE TABLE Aluga_Livro(quem_alugou INTEGER, livro_alugado INT, FOREIGN KEY (quem_alugou) REFERENCES Pessoa(cpf),
    FOREIGN KEY (livro_alugado) REFERENCES Biblioteca(id))"""
    cursor.execute(criarAG) 
    cursor.commit    
    print("Tabela Aluga_Livro criada")

print("O que você quer fazer?")     
print("(1) Ir para Biblioteca")
print("(2) Cadastro de Pessoas")
print("(3) Sistema de alugar livros") 
escolha = input()
print("-"*40)

escolha = int(escolha)
if escolha == 1:
    print("(1) Cadastrar um livro")
    print("(2) Deletar um livro")
    print("(3) Vizualizar Biblioteca") 
    acao = int(input())
    print("-"*40)
    if acao == 1:
        N = input("Nome:")
        A = input("Autor:")
        S = input("Status:")
        livro = f"""INSERT INTO Biblioteca(nome,
        autor, stat) VALUES ('{N}', '{A}', '{S}');"""
        cursor.execute(livro)
        cursor.commit()
        print("Livro cadastrado")
    elif acao == 2:
        N = input("Digite o nome do livro que quer deletar:")
        livro = f"""DELETE FROM Biblioteca WHERE nome = '{N}' ;"""
        cursor.execute(livro)
        cursor.commit()
        print("Livro deletado")
    elif acao == 3:    
        ver = "SELECT * FROM Biblioteca;"
        df = pd.read_sql_query(ver, conexao)
        print(df)
        
             
             
elif escolha == 2:
    print("(1) Quero me cadastrar")
    print("(2) Deletar um cadastro")
    print("(3) Vizualizar cadastrados") 
    acao = int(input())
    if acao == 1:
        N = input("Nome:")
        T = int(input("Telefone:"))
        pessoa = f"""INSERT INTO Pessoa(nome,
        telefone) VALUES ('{N}', '{T}');"""
        cursor.execute(pessoa)
        cursor.commit()
        print("Usuário cadastrado")
    elif acao == 2:
        N = input("Digite o nome da pessoa que quer deletar:")
        pessoa = f"""DELETE FROM Pessoa WHERE nome = '{N}' ;"""
        cursor.execute(pessoa)
        cursor.commit()
        print("Usuario deletado")
    elif acao == 3: 
        ver = "SELECT * FROM Pessoa;"
        df = pd.read_sql_query(ver, conexao)
        print(df)
    print("-"*40)
    
    
    
    
elif escolha == 3:    
    print("(1) Alugar Livro")
    print("(2) Devolver livro")
    print("(3) Verificar status de livros")     
    acao = int(input())
    if acao == 1:
        N = input("Nome do Livro:")
        pegando_id = f"""SELECT id FROM Biblioteca WHERE nome = '{N}'; """
        book = cursor.execute(pegando_id).fetchone()[0]
        CPF = input("Seu CPF:")
        alugando = f"""INSERT INTO Aluga_Livro(quem_alugou, livro_alugado) VALUES ({book}, {CPF})"""
        cursor.execute(alugando)
        cursor.commit()
        atualizando = f"""UPDATE Biblioteca SET stat = 'Alugado' WHERE nome = '{N}';""" 
        cursor.execute(atualizando)
        cursor.commit()
        print("Livro Alugado :)")
        
    elif acao == 2:
        N = input("Nome do Livro:")
        pegando_id = f"""SELECT id FROM Biblioteca WHERE nome = '{N}'; """
        book = cursor.execute(pegando_id).fetchone()[0]
        devolvendo = f"""DELETE FROM Aluga_Livro WHERE livro_alugado = {book};"""
        cursor.execute(devolvendo)
        cursor.commit()
        atualizando = f"""UPDATE Biblioteca SET stat = 'Disponivel' WHERE nome = '{N}';"""
        cursor.execute(atualizando)
        cursor.commit()
        print("Livro Devolvido")
        
    elif acao == 3:
        N = input("Nome do livro:")
        book = f"SELECT id, nome, stat FROM Biblioteca WHERE nome LIKE '{N}%';"
        df = pd.read_sql_query(book, conexao)
        print(df)
        
    print("-"*40)
cursor.close()