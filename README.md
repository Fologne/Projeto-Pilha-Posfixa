# 🧮 Calculadora com Pilha em C — Avaliação de Expressões com Variáveis

Este projeto implementa uma **calculadora científica em linguagem C**, capaz de **analisar e calcular expressões matemáticas** inseridas pelo usuário, utilizando o **método de pilha (stack)**.  

O sistema permite ao usuário definir **funções com múltiplas variáveis**, atribuir valores a elas e obter o resultado da expressão — tudo processado de forma **pós-fixa (notação polonesa reversa)**.

---

## ⚙️ Funcionalidades

| Função | Descrição |
|--------|------------|
| ➕ **Inserir expressão matemática** | O usuário pode digitar uma expressão infixa (ex: `3 + x * (y - 2)`) |
| 🔄 **Conversão infixa → pós-fixa** | O programa converte automaticamente a expressão para notação pós-fixa usando pilha |
| 🧠 **Análise de variáveis** | O programa identifica as variáveis existentes e solicita ao usuário os valores delas |
| 🧮 **Cálculo do resultado** | A expressão é avaliada usando a pilha, respeitando as prioridades dos operadores |
| 📋 **Menu interativo** | Interface no terminal para fácil navegação entre as opções |

---

## 🗂 Estrutura do Projeto

📦 CalculadoraPilha

┣ 📜 main.c # Função principal e controle do fluxo do programa

┣ 📜 menu.c # Sistema de menu interativo

┣ 📜 menu.h # Cabeçalho do menu

┣ 📜 func.c # Manipulação de expressões e variáveis

┣ 📜 func.h # Cabeçalho das funções de expressão

┣ 📜 pfloat.c # Pilha de valores do tipo float (usada na avaliação)

┣ 📜 pfloat.h # Cabeçalho da pilha de floats

┣ 📜 pilha.c # Pilha de caracteres (para operadores)

┣ 📜 pilha.h # Cabeçalho da pilha de caracteres

┗ 📜 README.md # Documentação do projeto


---

## 🔧 Tecnologias e Conceitos

- Linguagem C padrão (C99+)
- Estrutura de dados **Pilha (Stack)**
- Conversão **Infixa → Pós-fixa**
- Avaliação de expressões matemáticas
- Manipulação dinâmica de variáveis
- Modularização de código com headers (`.h`)
- Tratamento de operadores e parênteses

---

## ▶️ Como Compilar e Executar

### 🔹 Compilação
```bash
gcc main.c menu.c func.c pilha.c pfloat.c -o calculadora
