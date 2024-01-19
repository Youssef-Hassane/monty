>,                              # Read two integers from input
>,                              # Read two integers from input
<<++++++[>-------->--------<<-] # Initialize cells for multiplication
>[                              # Multiplication loop start
  [>+>+<<-]                     # Double the second number, halve the first
  >[<+>-]                       # Move result
  <<-                           # Position for next loop check
]
>[-]>+>>++++++++++<             # Setup for division
[
  ->-[>>>]++++++++++            # Division calculation
  <<+[<<<]>>>>                  
]
<-<++++++++++                   # More setup for division/multiplication
>>>[-<<<->>>]<<<<               # Finalize division/multiplication
++++++[>++++++++>               # Setup for output
  [++++++++>]                   # Adjust for ASCII output
  <[<]>-                        # More adjustments
]
>>[.<<]                         # Output the result
<[<<]>>.                        # Output newline
>>,
