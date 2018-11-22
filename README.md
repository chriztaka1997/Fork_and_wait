# Fork_and_wait
Creation and inheritance of child processes with fork and wait

Implement a string replacement software and count the number of times some given string is replaced in a plain text document.
Software components:
The UI (not GUI) program is the interface with the user. Prompt your user to enter a
target string and the replacement string. All target strings in some document2 are to be replaced with the replacement string. Here, spawn a child process to perform the replacement task. Allow the child process to finish and output the number of string replaced (if any), before prompting the user for the next pair of strings. If the user enter the string “!wq”, terminate the program.

To simplify the programming, a lengthy (300 words minimum) plain text document (e.g. excerpt of a web article) can be hard coded in the program as a C++ string object (or equivalent).

The child process is spawned by the UI process to replace and count the number of times a string is replaced in the document. Output the count and terminate (if count isn't zero.) Note: Each child can work with the original/initial copy of the document.

   
Injected bug: When a replacement should fail, i.e. count is zero, program your child
process to redo and repeat the failed replacement over and over (indefinitely). This bug
would require user's intervention at a separate terminal to terminate the child process
gracefully via command console (w/o terminating the parent process). To denote its
eternal execution, the child process prints a dot (.) prior to each repeated attempt.
