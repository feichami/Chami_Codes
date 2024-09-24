Operation	Result
| Expression         | Description                            |
|--------------------|----------------------------------------|
| `x + y`            | Sum of x and y                         |
| `x - y`            | Difference of x and y                  |
| `x * y`            | Product of x and y                     |
| `x / y`            | Quotient of x and y                    |
| `x // y`           | Floored quotient of x and y            |
| `x % y`            | Remainder of x/y                       |
| `-x`               | x negated                              |
| `+x`               | x unchanged                            |
| `abs(x)`           | Absolute value (or magnitude) of x     |
| `int(x)`           | x converted to integer                 |
| `float(x)`         | x converted to floating point          |
| `divmod(x, y)`     | The pair (x // y, x % y)               |
| `pow(x, y)` or `x ** y` | x to the power y                  |


| Escape Sequence      | Description                                |
|----------------------|--------------------------------------------|
| `\newline`           | Line continuation                          |
| `\\`                 | Backslash                                  |
| `\'`                 | Single quote                               |
| `\"`                 | Double quote                               |
| `\a`                 | ASCII Bell (BEL)                           |
| `\b`                 | Backspace                                  |
| `\f`                 | Form feed                                  |
| `\n`                 | Linefeed                                   |
| `\r`                 | Carriage Return                            |
| `\t`                 | Horizontal Tab                             |
| `\v`                 | Vertical Tab                               |
| `\ooo`               | ASCII character (octal value ooo)          |
| `\xhhh`              | ASCII character (hex value hhh)            |
| `\uxxxx`             | Unicode Character with 16-bit hex value xxxx |
| `\Uxxxxxxxx`         | Unicode Character with 32-bit hex value xxxxxxxx |



Strings example
<!-- #!/usr/bin/env python3
print("This is a literal string", 'and so is this')
print('"Double quotes" inside of single quotes')
print("'Single quotes' inside of double quotes")
print("A double quote \" inside double quotes")
print(r"A double quote \" inside a raw literal string")
print("A as unicode: \x41")

spades = """Royal Straight Flush \
\U0001F0A1 \U0001F0AE \U0001F0AD \U0001F0AB \U0001F0AA
"""
print(spades)

diamonds = """Royal Straight Flush \
\U0001F0C1 \U0001F0CE \U0001F0CD \U0001F0CB \U0001F0CA
"""
print(diamonds) -->

Seq. Operations

<!-- #!/usr/bin/env python3
# The concatenation operator (+)
first_name = "Casey"
last_name = "Jackson"
full_name = first_name + " " + last_name
print(full_name)  # Casey Jackson

# Note the automatic string concatenation below
fullName = "Casey" " " "Jackson"
print(fullName)

# The asterisk (*) operator
stars = "*" * 12
pounds = 5 * "#"
print(stars, ":", pounds)  # ************ : #####

# The in operator is convenient for membership tests
x = "Hello there"
print('t' in x, 'ell' in x, 'hell' in x)  # True True False -->

Indexing and Slicing

<!-- #!/usr/bin/env python3
spam = "Spam and eggs"
delim = " | "
# Indexing
print(spam[0], spam[3], spam[-1], spam[-4], sep=delim)

# Slicing
print(spam[2:7], spam[5:], spam[:8], sep=delim)

# Slicing from end
print(spam[-3:-1], spam[-3:], spam[:-1], sep=delim)
print()

# Extended Slicing
alphabet = "abcdefghijklmnopqrstuvwxyz"
print(alphabet[2:18:3])
start = 18
print(alphabet[start::1])
print(alphabet[::1]) -->