PROJECTS=001-intro

.PHONY: all $(PROJECTS)

all: $(PROJECTS)

clean:
	for dir in $(PROJECTS); do \
        make clean -C $$dir; \
    done

001-intro:
	make -C 001-intro

clean-001-intro:
	make clean -C 001-intro

