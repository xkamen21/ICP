# ICP
### Projekt:
    Aplikace pro zobrazení linek hromadné dopravy a sledování jejich pohybu

### Autoři:
    Daniel Kamenický (xkamen21), Marek Fiala (xfiala60)

### Popis:
    Aplikace po spuštění načte mapu. Mapa se skládá z ulic, zastávek a vozidel. Dále se v aplikaci vyskytují jednotlivé linky s konkrétním rozpisem výjezdů.
    Během průběhu plynutí času, vozidla, reprezentujicí autobusy dopravní společnosti, vyjiždí ze svých počatečních bodů. Aplikace simuluje průběh dopravy autobusů v čase.
    Aplikace nadále umožňuje změnu času, nastavení zpoždění na celé délce konkrétní ulice a změnu rychlosti plynutí času.

### Postavení a spuštění aplikace:
    Pro správné spuštění aplikace postupně následujte níže zmíněné kroky:
				- pro přeložení zadejte 'make'        
				- pro spuštění zadejte 'make run'
				- pro vyčištění zdejte 'make clean'

### Dokumentace:
		- pro vygenerování dokumentace zadejte 'make doxygen', v adresáři /doc/html je soubor index.html obsahujicí dokumentaci

### Zabalení do archívu:
		- pro zabalení do archívu zadejte 'make pack'

### Omezení:
    Nenaimplementováno uzavření ulic.
