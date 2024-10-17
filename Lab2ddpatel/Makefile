# Name: Your Name or Group name
# Email: email address(es)
# Sample Makefile


# This is a Gnu compatible Makefile.  You can read the documentation online by searching Gnu Make
# All coding projects must include a similar Makefile, named "Makefile".  See submission guidelines

STD=-std=c++11
OPT=-g
TMPMAKE=tmpMake
CXXFLAGS=${STD} ${OPT}
CFLAGS=${OPT}

%.o: %.cxx
	$(CXX) -c $(CXXFLAGS) $<

%: %.cxx
	$(CXX) -o $@ $(CXXFLAGS) $<

DECKSRCS=deckmain_ddpatel.cxx deck_ddpatel.cxx shuffle_ddpatel.cxx card_ddpatel.cxx
DECKOBJS=$(DECKSRCS:.cxx=.o)
CARDSRCS=card_ddpatel.cxx cardmain_ddpatel.cxx
CARDOBJS=$(CARDSRCS:.cxx=.o)
POKERSRCS=poker_ddpatel.cxx pokermain_ddpatel.cxx deck_ddpatel.cxx shuffle_ddpatel.cxx card_ddpatel.cxx
POKEROBJS=$(POKERSRCS:.cxx=.o)
ALL=decktest cardtest pokertest

all: $(ALL)

decktest:	$(DECKOBJS)
	$(CXX) -o $@ $(CXXFLAGS) $+

cardtest:	$(CARDOBJS)
	$(CXX) -o $@ $(CXXFLAGS) $+

pokertest:	$(POKEROBJS)
	$(CXX) -o $@ $(CXXFLAGS) $+

clean:
	/bin/rm -f $(DECKOBJS) $(CARDOBJS) $(POKEROBJS) $(ALL)
	/bin/rm -f poker.tar
	/bin/rm -rf $(ALL:=.dSYM)

depend: $(DECKSRCS) $(CARDSRCS) $(POKERSRCS)
	/bin/rm -f $(TMPMAKE)
	sed -e '/^# DEPENDENTS/,$$d' Makefile > $(TMPMAKE)
	echo '# DEPENDENTS' >> $(TMPMAKE)
	$(CXX) -MM $+ >> $(TMPMAKE)
	/bin/mv -f $(TMPMAKE) Makefile

tar:
	tar cf poker.tar Makefile *.cxx *.h

# DEPENDENTS
deckmain.o: deckmain_ddpatel.cxx card_ddpatel.h deck_ddpatel.h
deck.o: deck_ddpatel.cxx card_ddpatel.h deck_ddpatel.h
shuffle.o: shuffle_ddpatel.cxx card_ddpatel.h deck_ddpatel.h
card.o: card_ddpatel.cxx card_ddpatel.h
card.o: card_ddpatel.cxx card_ddpatel.h
cardmain.o: cardmain_ddpatel.cxx card_ddpatel.h
poker.o: poker_ddpatel.cxx card_ddpatel.h deck_ddpatel.h poker_ddpatel.h 
pokermain.o: pokermain_ddpatel.cxx card_ddpatel.h deck_ddpatel.h poker_ddpatel.h 
deck.o: deck_ddpatel.cxx card_ddpatel.h deck_ddpatel.h
shuffle.o: shuffle_ddpatel.cxx card_ddpatel.h deck_ddpatel.h
card.o: card_ddpatel.cxx card_ddpatel.h
