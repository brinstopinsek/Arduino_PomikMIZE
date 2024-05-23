# Arduino_PomikMize
Projekt za premik mize gor in dol - Arduino

NAVODILA: Pomik MIZE: Krmilje naj krmili pomik mize, to je v smeri gor - dol (gor - sveti zelena LED, dol, sveti rdeča LED), prek aktiviranja ustreznih elektromagnetnih ventilov. Skrajni legi mize sta indicirani s končnim stikalom v spodnji oziroma zgornji legi, kjer se gibanje zaustavi. Pomik aktiviramo s tipko GOR za pomik mize navzgor in tipko DOL za pomik mize navzdol. Gibanje lahko v kateremkoli trenutku zaustavimo z aktiviranjem tipke STOP. Sprememba smeri pomika naj bo omogočena z aktiviranjem tipke GOR ali DOL brez predhodnega aktiviranja tipke STOP.

KOSOVNICA: 
- Arduino Uno 
- BreadBoard 
- USB kabel 
- 2x LED dioda 
- Povezovalne žice 
- 3x Tipke 
- 2x Rele 
- 3x Upor (1000Ω) 
- 2x Upor (220Ω) 
- Elektro motor


VHODI:
| Oznaka v načrtu | Naslov operanda | Vrsta kontakta | Pomen |
| --- | --- | --- | --- |
| S3 | Tipka | O, tipka | Za pomik mize dol |
| S1 | Tipka | O, tipka | Za ustavitev mize |
| S2 | Tipka | O, tipka | Za pomik mize gor |


IZHODI:
| Oznaka v načrtu | Naslov operanda | Aktiven pin | Pomen |
| --- | --- | --- | --- |
| D1 | LED | 12 | Zasvetlitev LED diode ob premiku gor |
| D2 | LED | 13 | Zasvetlitev LED diode ob premiku dol |
| K2 | Rele | 2 | Zadolžen za obračanje motorčka na desno stran |
| K3 | Rele | 3 | Zadolžen za obračanje motorčka na levo stran |



  ![Vezje](https://raw.githubusercontent.com/brinstopinsek/Arduino_PomikMize/main/Vezje.png)

  ![VezalnaShema](https://raw.githubusercontent.com/brinstopinsek/Arduino_PomikMize/main/VezalnaShema.png)

  https://github.com/brinstopinsek/Arduino_PomikMize/assets/170461048/d6dc1a42-009d-4221-b2c0-cba744af1574


  

KOMENTAR:
Projekt deluje dobro. Zelo dolgo sva se pa zadržala pri tipki stop, ki na začetku ni delovala. To sva nato popravila s spremembo tipke in delčkom kode. Če bi si izmislila še kakšno nadgradnjo tega projekta, bi takoj še dodala dodatko LED diodo. Ta bi se prižgala, ko bi se miza ob premikanju ustavila. Lahko bi dodala tudi kakšen časovnik, ki bi blokiral tipko gor in dol za nekaj sekund, po tem ko smo se ustavili s tipko stop.
