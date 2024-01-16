# Wenglor-sample-exercises
# Mini Praksa u Wenglor - Zadaci u C jeziku

Ovaj repozitorijum sadrži rešenja zadatka koje sam radio/la tokom svoje mini prakse u firmi Wenglor. Zadaci su napisani u programskom jeziku C.

## Zadatak 1

### Opis zadatka

Napisati program u C programskom jeziku gde korisnik može unositi podatke:
- Celobrojne vrednosti (integer) - pozitivne ili negativne
- Slovo (char) ili reči (string)

Kao rezultat, program treba izračunati aritmetičku, geometrijsku ili harmonijsku srednju vrednost svih do tada unetih brojeva, u zavisnosti od unetog slova ili reči.

### Primer

**Ulaz:**
15
10
25
geometrijska

**Rezultat.txt:**
14.422495703074


### Kako koristiti

Za unos podataka koristi se standardni ulaz.

- Ako je pristigli podatak celobrojna vrednost, smestiti ga u dinamički kreiran niz.
- Ako je pristigli podatak slovo ili reč, proveriti da li je u pitanju aritmeticka, geometrijska ili harmonijska srednja vrednost i izračunati je.

**Napomena:** Ime fajla treba biti Rezultat.txt.

## Zadatak 2

### Opis zadatka

Održavaju se takmičenja iz matematike, fizike, hemije i biologije za srednje škole. Potrebno je napraviti sistem (program u programskom jeziku C) koji čuva rezultate i vrši neke jednostavnije obrade nad njima.

### Primer

**Ulaz:**
Milan Mitrovic 2007 Srednja_Medicinska_Skola_Beograd II Biologija 76.53
Vladimir Petrovic 2008 Gimnazija_Sveti_Sava_Beograd III Matematika 58.24


**Matematika_III.txt:**
Petar Radeta 2008 Matematicka_Gimnazija_Beograd 92.25
Stefan Stankovic 2008 X_Gimnazija_Beograd 86.25


**Kako koristiti**

Podaci se unose sa standardnog ulaza u formatu Ime Prezime Godiste Srednja_skola Godina Oblast Broj_poena.

Kada korisnik umesto standardnog unosa unese "---", program treba kreirati posebne fajlove za svaku godinu i svaku oblast (npr Biologija_I.txt, Biologija_II.txt, Biologija_III.txt, Biologija_IV.txt, Matematika_I.txt, Matematika_II.txt, i tako dalje).

U fajlovima treba ispisati sortirane podatke o takmičarima: Ime Prezime Godiste Srednja_skola Broj_poena.

## Kako koristiti

- Klonirajte repozitorijum: `git clone https://github.com/tvoje-ime/Wenglor-sample-exercises.git`
- Kompajlirajte program: `gcc -o zadatak1 zadatak1.c funkcije.c` i `gcc -o zadatak2 zadatak2.c funkcije.c`
- Pokrenite program: `./zadatak1` i `./zadatak2`

## Linkovi:
  - https://www.wenglor.com/en/
  - https://www.youtube.com/@wenglorsensoric 