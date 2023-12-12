
- [Descrição da Entrada do Autômato](#descrição-da-entrada-do-autômato)

## Descrição da Entrada do Autômato

- A entrada é uma 5-tupla `(`
  - `Q` é um conjunto finito e não vazio de estados (`{ q0, q1, q[0-9] }`)
  - `Σ` é o alfabeto, conjunto de símbolos de entrada, ou seja, o conjunto de símbolos permitidos para aparecer no conteúdo inicial da fita (`{a, b, [a-z]...}`)
  - `Γ` é um conjunto finito e não vazio de símbolos do alfabeto da fita (`{B, [A-Z]...}`);
  - `δ` é o conjunto de transições:
    - exemplo: `{(q1, A) -> (q2, b, D)}`
      - do estado `q1`, substituindo `A` por `b`, indo para o estado `q2` e movendo para a direita (`D`)
      - obs.: `D` significa direita e `E` esquerda :/
  - estado inicial (`q0` geralmente)
  - conjunto de estados finais (`{ q[0-9] }`)
- `)`
