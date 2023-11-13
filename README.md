
 
3.8 The Invisible Plus Sign
This one is a little bizarre. It is an invisible plussign. Instead of printing a plus on positive numbers(and zero), we print a space where the sign would go.This can be useful in printing left-justiﬁed numberswhere you want the minus signs to really stand out.Notice these two alternatives.
printf
 produces
("%+-5d",0) +0("%+-5d",-7) -7("%+-5d",1560133635) +1560133635("%+-5d",-2035065302) -2035065302printf
 produces
("%-5d",0) 0("%-5d",-7) -7("%-5d",1560133635) 1560133635("%-5d",-2035065302) -2035065302
Remember from above that the format speciﬁer
%-5d
 we get the following results (shown again foreasier comparison).
printf
 produces
("%-5d",0) 0("%-5d",-7) -7("%-5d",1560133635) 1560133635("%-5d",-2035065302) -2035065302
Notice that the plus signs disappear, but the signstill takes up space at the front of the number.Notice also that we can combine several optionsin the same format speciﬁer. In this case, we havecombined the options plus, minus, and ﬁve, or space,minus, and ﬁve, or just minus and ﬁve.
3.9 Plus, Space, and Zero
Here is another example of combining several optionsat the same time.Using the format speciﬁer
 %05d
 or
 %05d
 we getthe following results.
printf
 produces
("%05d",0) 0000("%05d",-7) -0007("%05d",1560133635) 1560133635("%05d",-2035065302) -2035065302
Using the format speciﬁer
 %+05d
 or
 %0+5d
 we getthe following results.
printf
 produces
("%+05d",0) +0000("%+05d",-7) -0007("%+05d",1560133635) +1560133635("%+05d",-2035065302) -2035065302
When we combine plus and space at the sametime, the space arranges for room for a sign andthe plus uses it. It is the same as if the space wasnot even speciﬁed. The plus takes priority over thespace.
3.10 Summary
The options are also called “ﬂags” and among them-selves they can appear in any order. Here is a partiallist.ﬂag eﬀectnone print normally (right justify, space ﬁll)
-
 left justify
0
 leading zero ﬁll
+
 print plus on positive numbers

 invisible plus signAfter the options, if any, the minimum ﬁeld widthcan be speciﬁed.
4 Printing Strings
The
 %s
 option allows us to print a string inside astring. Here is an example.
char * grade;if ( year == 11 ) grade = "junior";printf ( "%s is a %s\n", "Fred", grade );
The left-justify ﬂag applies to strings, but of course the zero ﬁll, plus sign, and invisible plus signare meaningless.
printf
 produces
("%5s","") ("%5s","a") a("%5s","ab") ab("%5s","abcdefg") abcdefgprintf
 produces
("%-5s","") ("%-5s","a") a("%-5s","ab") ab("%-5s","abcdefg") abcdefg

 
5 Floating Point
Floating point numbers are those like
 3.1415
 thathave a decimal point someplace inside. This is incontrast to ordinary integers like
 27
 that have nodecimal point.All the same ﬂags and rules apply for ﬂoatingpoint numbers as do for integers, but we have a fewnew options. The most important is a way to spec-ify how many digits appear after the decimal point.This number is called the
 precision
 of the number.For ordinary commerce, prices are often men-tioned as whole dollars or as dollars and cents (zeroor two digits of precision). For gasoline, prices arementioned as dollars, cents, and tenths of a cent(three digits of precision). Here are some exam-ples of how to print these kinds of numbers. Let
e=2.718281828
.
printf
 produces
("%.0f",e) 3("%.0f.",e) 3.("%.1f",e) 2.7("%.2f",e) 2.72("%.6f",e) 2.718282("%f",e) 2.718282("%.7f",e) 2.7182818
Notice that if a dot and a number are speciﬁed, thenumber (the precision) indicates how many placesshould be shown after the decimal point.Notice that if no dot and precision are speciﬁed for
%f
, the default is
 %.6f
 (six digits after the decimalpoint).Notice that if a precision of zero is speciﬁed, thedecimal point also disappears. If you want it back,you must list it separately (after the
 %f
 format spec-iﬁer).We can specify both a width and a precision atthe same time. Notice especially that
 5.2
 meansa total width of ﬁve, with two digits after the deci-mal.
 It is very common and natural to think itmeans ﬁve digits in front of the decimal andtwo digits after, but that is not correct.
 Becareful.
printf
 produces
("%5.0f",e) 3("%5.0f.",e) 3.("%5.1f",e) 2.7("%5.2f",e) 2.72("%5.7f",e) 2.7182818
We can also combine precision with the ﬂags welearned before, to specify left justiﬁcation, leadingzeros, plus signs, etc.
printf
 produces
("%5.1f",e) 2.7("%-5.1f",e) 2.7("%+5.1f",e) +2.7("%+-5.1f",e) +2.7("%05.1f",e) 002.7("%+05.1f",e) +02.7("%05.1f",e) 02.7("%-5.1f",e) 2.7
6 Designing The Perfect Spec
If you are designing a
 printf
 format speciﬁer, theﬁrst step is to decide what kind of a thing you areprinting. If it is an integer, a ﬂoat, a string, or a char-acter, you will make diﬀerent choices about whichbasic format to use.The second big question is how wide your ﬁeldshould be. Usually this will be the size of the biggestnumber you ever expect to print under normal cir-cumstances. Sometimes this is controlled by theamount of space that is provided on a pre-printedform (such as a check or an invoice).Decide what you would like printed under a va-riety of circumstances. In this paper we have of-ten illustrated the results by using a small posi-tive number, a small negative number, an oversizedpositive number, and an oversized negative number.You should include this options as well as large (butnot oversized) numbers. Design your format for thebiggest number that you would normally expect tosee.
7 Hints for the Test
The
 printf
 test includes a variety of matching prob-lems. They are designed to be tricky, and studentfeedback indicates that if anything, they are moretricky that expected.You can use the process of elimination to makethis test very fast and accurate. As you look at acommon feature in the answer line, you can rule outall those
 printf
 statements that do not have thatfeature. Very quickly you can narrow your optionsto one or two.

 
7.1 Easy Features
It is easy to see if the short numbers have leadingzeros. If so, there must be a zero in the formattingspeciﬁcation.It is easy to see if the positive numbers have plussigns. If so, there must be a plus in the formattingspeciﬁcation.
7.2 Before, Between, and Behind
The next thing to watch for is the before, between,and behind of the number that is printed. In a for-matting speciﬁcation like
 x%5dz
 there is an
 x
 beforethe number and a
 z
 behind the number. The
 x
 and
z
 are not part of the format speciﬁcation, but theyare part of the printed result. Everything else thatprints is “between.”To decide whether there is anything before or be-hind a number, look at the oversized negative num-ber. Any spaces before it are surely before the for-mat speciﬁcation. Any spaces behind it are surelybehind the format speciﬁcation. Here is an example.If -2035065302 prints as
 -2035065302
, you canbe sure that the
 printf
 string is
 %...
, with twospaces before the formatting speciﬁcation and onespace behind. That is because all the print positionsbetween (the
 %
 and whatever goes with it) are usedup by the oversized number.Once you have determined what is before and be-hind, you can use that information to match againstthe matching choices. Often this will give you theanswer directly.
7.3 The Invisible Plus Sign
Compare the oversized negative number to the over-sized positive number. If the positive number hasan extra space in front, it is an invisible plus sign.If there is no extra space, there is no invisible plussign.
7.4 Left Justiﬁcation
Subtract the before and behind. Look at what is left.Look at the small negative number. Where are theextra spaces printed? If the are in front, the numberis right justiﬁed. If they are in back, the number isleft justiﬁed. If they are in front and in back, youdid something wrong
