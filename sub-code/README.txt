This README refers to trivialCipher.cpp and myCipher

Make commands:

make
	g++ -Wall trivialCipher.cpp -o myCipher
	Normal make command.

Usage:
	./myCipher [text file]
	This will take the first line of the text file as an argument (must be
	all lowercase).

	./myCipher
	You will be prompted for an input using the standard input (must be
	all lowercase).

This program will allow a user to decrypt a trivial substitution ciphertext
step-by-step until decoded. If the user gets lost or makes a mistake they can
be prompted to type 'R' to reset all changes to the ciphertext.

The following cipher text will be used as an example:
    gur fpvragvsvp gurbel v yvxr orfg vf gung gur evatf bs fnghea ner pbzcbfrq
    ragveryl bs ybfg nveyvar yhttntr

This can be found the file ciphertext.txt

First we notice that "gur" appears twice throughout the cipher text, giving a
great chance that this is "the"
      (the) fpv(e)a(t)vsvp (the)bel v yvx(e) o(e)f(t) vf (th)n(t) (the) evatf bs fn(t)hea ne(e)
      pbzcbf(e)q (e)a(t)ve(e)yl bs ybf(t) nveyva(e) yhttnt(e)

Next we substitute 'n' for 'a' to make "that"
      (the) fpv(e)a(t)vsvp (the)bel v yvx(e) o(e)f(t) vf (that) (the) evatf bs f(at)hea
      (a)e(e) pbzcbf(e)q (e)a(t)ve(e)yl bs ybf(t) (a)veyva(e) yhtt(a)t(e)
Next substitute 'e' for 'r' to make "are"
      (the) fpv(e)a(t)vsvp (the)b(r)l v yvx(e) o(e)f(t) vf (that) (the)
      (r)vatf bs f(at)h(r)a (are) pbzcbf(e)q (e)a(t)v(re)yl bs ybf(t)
      (a)v(r)yva(e) yhtt(a)t(e)

Substitute 'v' for 'i' because it appears it is still the subject
      (the) fp(ie)a(ti)s(i)p (the)b(r)l (i) y(i)x(e) o(e)f(t) (i)f (that)
      (the) (ri)atf bs f(at)h(r)a (are) pbzcbf(e)q (e)a(tire)yl bs ybf(t)
      (air)y(i)a(e) yhtt(a)t(e)

Substitute 'f' for 's'
      (the) (s)p(ie)a(ti)s(i)p (the)b(r)l (i) y(i)x(e) o(est) (is) (that)
      (the) (ri)at(s) bs (sat)h(r)a (are) pbzcb(se)q (e)a(tire)yl bs yb(st)
      (air)y(i)a(e) yhtt(a)t(e)

Substitute "bs" for "of"
      (the) (s)p(ie)a(tifi)p (theor)l (i) y(i)x(e) o(est) (is) (that) (the)
      (ri)at(s) (of) (sat)h(r)a (are) p(o)zc(ose)q (e)a(tire)yl (of) y(ost)
      (air)y(i)a(e) yhtt(a)t(e)

Substitute 'y' for 'l' and 'x' for 'k'
      (the) (s)p(ie)a(tifi)p (theor)l (i) (like) o(est) (is) (that) (the)
      (ri)at(s) (of) (sat)h(r)a (are) p(o)zc(ose)q (e)a(tirel)l (of) (lost)
      (airli)a(e) (l)htt(a)t(e)
Solve for the words "scientific", "theory", and "rings"
      (the) (scientific) (theory) (i) (like) o(est) (is) (that) (the) (rings)
      (of) (sat)h(rn) (are) (co)zc(ose)q (e)a(tirely) (of) (lost) (airline)
      (l)h(ggage)

Finish
      the scientific theory i like best is that the rings of saturn are
      composed entirely of lost airline luggage
