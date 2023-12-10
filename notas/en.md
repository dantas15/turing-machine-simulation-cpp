
- [automata input description](#automata-input-description)

## automata input description

- the input is a 5-tuple `(`
  - `Q` is a finite, non-empty set of states (`{ q0, q1, q[0-9] }`)
  - `Σ` is the set of input symbols, that is, the set of symbols allowed to appear in the initial tape contents (`{a, b, [a-z]...}`)
  - `Γ` is a finite, non-empty set of tape alphabet symbols (`{B, [A-Z]...}`);
  - `δ` is the set of transitions:
    - example: `{(q1, A) -> (q2, b, D)}`
      - from `q1` state, replacing `A` for `b`, going to `q2` state and moving to the right (`D`)
      - obs.: `D` means right and `E` left :/
  - initial state (`q0` usually)
  - set of final states (`{ q[0-9] }`)
`)`
