fermat:
	gcc -c func.c func.h Fermat.c -lgmp
	gcc func.o Fermat.o -o Fermat -lgmp
	./Fermat 40 285542542228279613901563566102164008326164238644702889199247456602284400390600653875954571505539843239754513915896150297878399377056071435169747221107988791198200988477531339214282772016059009904586686254989084815735422480409022344297588352526004383890632616124076317387416881148592486188361873904175783145696016919574390765598280188599035578448591077683677175520434074287726578006266759615970759521327828555662781678385691581844436444812511562428136742490459363212810180276096088111401003377570363545725120924073646921576797146199387619296560302680261790118132925012323046444438622308877924609373773012481681672424493674474488537770155783006880852648161513067144814790288366664062257274665275787127374649231096375001170901890786263324619578795731425693805073056119677580338084333381987500902968831935913095269821311141322393356490178488728982288156282600813831296143663845945431144043753821542871277745606447858564159213328443580206422714694913091762716447041689678070096773590429808909616750452927258000843500344831628297089902728649981994387647234574276263729694848304750917174186181130688518792748622612293341368928056634384466646326572476167275660839105650528975713899320211121495795311427946254553305387067821067601768750977866100460014602138408448021225053689054793742003095722096732954750721718115531871310231057902608580607


miller:
	gcc -c func.c func.h Miller_Rabin.c -lgmp
	gcc func.o Miller_Rabin.o -o Miller_Rabin -lgmp
	./Miller_Rabin 40 285542542228279613901563566102164008326164238644702889199247456602284400390600653875954571505539843239754513915896150297878399377056071435169747221107988791198200988477531339214282772016059009904586686254989084815735422480409022344297588352526004383890632616124076317387416881148592486188361873904175783145696016919574390765598280188599035578448591077683677175520434074287726578006266759615970759521327828555662781678385691581844436444812511562428136742490459363212810180276096088111401003377570363545725120924073646921576797146199387619296560302680261790118132925012323046444438622308877924609373773012481681672424493674474488537770155783006880852648161513067144814790288366664062257274665275787127374649231096375001170901890786263324619578795731425693805073056119677580338084333381987500902968831935913095269821311141322393356490178488728982288156282600813831296143663845945431144043753821542871277745606447858564159213328443580206422714694913091762716447041689678070096773590429808909616750452927258000843500344831628297089902728649981994387647234574276263729694848304750917174186181130688518792748622612293341368928056634384466646326572476167275660839105650528975713899320211121495795311427946254553305387067821067601768750977866100460014602138408448021225053689054793742003095722096732954750721718115531871310231057902608580607



clean:
	rm -f -v *.o 
	rm -f -v *.gch
	rm -f -v Miller_Rabin
	rm -f -v Fermat