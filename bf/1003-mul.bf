>, >, <<  # Read three inputs and move tape head to a neutral position
+++++ +   # Add 6 to current cell
[         # Start a loop until the current cell reaches 0
 >----- ---   # Subtract 8 from the cell to the right
 >----- ---   # Subtract 8 from the next cell to the right
 <<-         # Move back to the loop control cell
]
> [            # Move to the next cell and start a loop
 >[>+>+<<-]    # Copy value to two cells to the right
 >[<+>-]       # Add the first copy back, effectively multiplying
 <<-           # Move back to the loop control cell
]
>[-]>+> >+++++ +++++<  # Clear the cell, move right, and initialize cells for the next operation
[                       # Start a loop until the current cell reaches 0
 - >- [>>>]+++++ +++++<<+  # Perform a series of operations, likely arithmetic, on adjacent cells
 [<<<]>>>>                 # Move the tape head to a new position
]
<-                     # Move tape head left
<+++++ +++++>>>[-<<<->>>]<<<  # Add 10 to current cell, perform moves and subtraction
<+++++ +                  # Add 10 to current cell
[
 >+++++ +++>             # Add 8 to the next cell
 [+++++ +++>]            # Add 8 to the next cell, nested loop for multiplication or power
 <[<]>-                  # Move back to starting position and decrement
]
>>[.<<]<[<<]>>.          # Output characters and move the tape head
>>,.                     # Move right, output character, read next input
