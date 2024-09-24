# # Operation	Result
# x + y	Sum of x and y
# x - y	Difference of x and y
# x * y	Product of x and y
# x / y	Quotient of x and y
# x // y	Floored quotient of x and y
# x % y	Remainder of x/y
# -x	x negated
# +x	x unchanged
# abs(x)	Absolute value (or magnitude) of x
# int(x)	x converted to integer
# float(x)	x converted to floating point
# divmod(x,y)	The pair (x // y, x % y)
# pow(x, y) or x ** y	x to the power y

# Sequence	Character/Meaning
# \newline	Line continuation
# \\	Backslash
# \'	Single quote
# \"	Double quote
# \a	ASCII Bell (BEL)
# \b	Backspace
# \f	Form feed
# \n	Linefeed
# \r	Carriage Return
# \t	Horizontal Tab
# \v	Vertical Tab
# \ooo	ASCII character (octal value ooo)
# \xhhh	ASCII character (hex value hhh)
# \uxxxx	Unicode Character with 16-bit hex value xxxx
# \Uxxxxxxxx	Unicode Character with 32-bit hex value xxxxxxxx


#!/usr/bin/env python3
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
print(diamonds)

x = "Hello there"
print('t' in x, 'ell' in x, 'Hell' in x)  # True True False