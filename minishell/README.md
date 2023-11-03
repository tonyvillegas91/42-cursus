# minishell

I had to implement 7 built-ins like in bash:

- echo (with -n option)
- cd
- pwd
- export
- unset
- env
- exit

I also had to handle redirections (<, <<, >, >>), multiple pipes (working in parallel), environment variables and some signals.

## What I learned:

It deepened our understanding of the terminal which is our working tool.
I learned a lot about file descriptors, forking processes and interprocess communication which is kinda obscur to me.
It was the first "big project" I had to do for both of me, it took me around a 2 months and a half, but in the end I think I ended up with a pretty solid shell that handles a lot of stuff, runs external programs and replicates bash in a lot of things.

If you wanna try it:

- clone this repo.
- run "make && ./minishell"
- have fun.

## Conclusion:

I had some "kill myself" moments during this project, especially with the parsing (it can be tricky), but in the end I think I really enjoyed it, and also I think it's a pretty usefull exercise as you learn a lot of things.
