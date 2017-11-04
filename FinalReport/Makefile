all:
	pdflatex report.tex
	@printf "\n********************************\n\n"
	bibtex report
	@printf "\n********************************\n\n"
	pdflatex report.tex
	@printf "\n********************************\n\n"
	pdflatex report.tex
	@printf "\n********************************\n\n"
	$(MAKE) clean
clean:
	rm -f *.aux
	rm -f *.toc
	rm -f *.out
	rm -f *.bbl
	rm -f *.blg
