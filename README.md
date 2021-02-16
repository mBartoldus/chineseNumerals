# chineseNumerals

## Disclaimers

I don't speak Chinese. I wrote this in 2019. At the time, I was dabbling in Japanese, which led to frequent encounters with Chinese numerals in the form of Kanji. It's really interesting stuff, but I'm no expert.

There's more than one set of Chinese numerals. This program outputs the ones used in prosaic writing, morphemes, and radicals. There's also a couple related systems that were historically used in financial records. This program would not be effective in forging those kinds of documents. Also, there were a couple options to represent 0, so I went with the simpler-looking one. But I also recognize the character "〇" is a little ambiguous. It could be a full stop, or a star (if you lived during the reign of Empress Wu). Or, it could just be a circle.

This program's output is only valid for positive integers up to (not including) 1,0000,0000

## How it works

Running the program starts a command line prompt that calls the function *to_chinese* on user input and prints the result. To end the program, press enter without typing any input.

The function *to_chinese* expects a string formatted in American decimal notation. That is to say, commas and leading zeroes are ignored, and "." or  any other non-numeric char is interpreted as the end of the number (fractions are not supported).

The return value is a string of Chinese character(s) representing that number as it might be said in a phrase. That is to say, 50 returns "五十" (five tens), as opposed to "五〇" (five zero).

## Examples

	to_chinese("3") == "三"

	to_chinese("500") == "五百"

	to_chinese("365.25") == "三百六十五"

	to_chinese("10,000") == "万"

	to_chinese("12345") == "万二千三百四十五"
