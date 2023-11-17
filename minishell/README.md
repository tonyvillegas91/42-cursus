# minishell

This project was a deep dive into the world of shell design and functionality. I recreated 7 essential built-in commands found in Bash:

echo (with -n option)
cd
pwd
export
unset
env
exit

## Additionally, the minishell handles features:

Redirections: (<, <<, >, >>)
Multiple pipes: (working in parallel)
Environment variables:
Signals:

## What I learned:

This project fundamentally transformed my knowledge about the terminal, our daily working tool. I gained a thorough understanding of:

File descriptors
Process forking
Interprocess communication
Though initially obscure, these concepts became much clearer as I delved deeper into minishell development.

This was my first "big project," spanning a challenging yet rewarding journey of 2.5 months. The result is a robust and versatile shell capable of handling numerous tasks, running external programs, and replicating many functionalities of Bash.

## Try it yourself:

Clone this repo.
Run make && ./minishell
Have fun!

## Conclusion:

Although aspects like parsing posed significant hurdles, the overall experience was both enjoyable and incredibly valuable. The project provided a unique learning opportunity and a chance to explore essential programming concepts.
