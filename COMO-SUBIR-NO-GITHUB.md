# Como subir este projeto no GitHub

Passo a passo para quem está publicando pela primeira vez.

## Antes de começar

Confira se o Git está instalado abrindo o terminal e rodando:

```bash
git --version
```

Se aparecer um número de versão, está tudo certo. Se der erro, instale a partir de https://git-scm.com

Se for a sua primeira vez usando Git nesta máquina, configure o seu nome e e-mail. Eles vão aparecer no histórico dos commits.

```bash
git config --global user.name "Eduardo Domingues"
git config --global user.email "seu-email@exemplo.com"
```

## Passo 1: crie o repositório no GitHub

Vá em https://github.com/new e preencha:

- **Repository name:** semaforo-do-silencio
- **Description:** Projeto STEAM de medição de ruído com Arduino para o 7º ano
- **Public** ou **Private**, como preferir

Importante: **não marque** as opções de adicionar README, .gitignore ou licença. Este projeto já tem os três. Se você marcar, o Git vai recusar o primeiro envio por conflito de histórico.

Clique em **Create repository** e deixe a página aberta, porque você vai precisar da URL.

## Passo 2: abra o terminal na pasta do projeto

Descompacte o arquivo .zip onde preferir e entre na pasta:

```bash
cd caminho/para/semaforo-do-silencio
```

No Windows, você pode abrir a pasta no Explorador, clicar com o botão direito em um espaço vazio e escolher **Abrir no Terminal**.

## Passo 3: envie para o GitHub

Rode os comandos abaixo, um de cada vez. Troque a URL do `remote` pela que o GitHub mostrou para você.

```bash
git init
git branch -M main
git add .
git commit -m "Projeto inicial do semaforo do silencio"
git remote add origin https://github.com/seu-usuario/semaforo-do-silencio.git
git push -u origin main
```

Na primeira vez o GitHub vai pedir autenticação. Se ele pedir senha no terminal, use um **token de acesso pessoal** no lugar da senha da conta, porque senha comum foi descontinuada. O token se cria em Settings, depois Developer settings, depois Personal access tokens.

## Depois disso

Sempre que editar o código no Arduino IDE e salvar, o ciclo é sempre o mesmo:

```bash
git add .
git commit -m "Ajuste dos limiares apos a calibracao"
git push
```

## Se algo der errado

**O push foi recusado dizendo que os históricos não têm relação.** Isso acontece quando o repositório foi criado com README no GitHub. Resolva com:

```bash
git pull origin main --allow-unrelated-histories
git push
```

**O Git reclama que a branch se chama master e não main.** Rode `git branch -M main` antes do push.

**Você quer conferir o que será enviado antes de mandar.** Use `git status` para ver a lista de arquivos.
