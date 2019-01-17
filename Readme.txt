This is the readme for writing the definition.txt, where we write Definition of the machine.

1. The first line corresponds to accepted letters(without braces and commas.).
For example: The language has letters: {a,b}.
The first line become: ab
2. The second line corresponds to states(without braces, commas and the prefix).
For example: The language has states: {q0,q1}
The second line becomes: 01
3. The third line corresponds to the transfer function: 
For example: if f(q0,a)=q0 , f(q0,b)=q1, f(q0,a)=q1, f(q1,b)=q0

	a	b
q0	q0	q1
q1	q1	q0

We write: 01,10 
4. The fourth line corresponds to the initial state:
For example: The initial state is q0,
We write: 0
5. The fifth line corresponds to the set of final states:(without braces, commas and prefix)
For example: The set of final states is: {q0,q1}
We write: 01


*****WARNING********
Please don't add extra lines or remove the existiong. 
Write in the same format as described above.
