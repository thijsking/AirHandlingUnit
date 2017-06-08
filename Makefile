all:
	$(MAKE) -C _TheUnit/
	$(MAKE) -C _Controls/

clean:
	$(MAKE) -C _TheUnit/ clean
	$(MAKE) -C _Controls/ clean

