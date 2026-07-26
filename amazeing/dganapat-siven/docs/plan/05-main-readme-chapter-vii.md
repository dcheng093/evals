# 05 — Main README satisfying Chapter VII in full

Source: `spec.md`

**What to build:** A stranger — peer, staff, or recruiter — opens the repository's front page and understands what the project is, how to run it, how to configure it, what is reusable, and how the team worked. Today roughly a third of Chapter VII is present, and every list in the file is indented four spaces, so Markdown renders it as a code block: the document whose stated purpose is quick understanding displays as grey monospace boxes.

Two sections are deliberately left as visible placeholders rather than written: the justification for the algorithm choice, which belongs to the teammate who made it, and the list of sources actually read. Chapter II warns against submitting content the author cannot defend under questioning, and both of these are cheap for an evaluator to test.

**Blocked by:**
- 01 — Restructure maze generation into an importable `mazegen` package. The "what is reusable and how" section describes the final layout, so it cannot be written before the layout is settled.
- 03 — Module documentation that ships inside the distribution. Chapter VII requires the same documentation to appear here, so it must exist first and the two copies must agree.

**Status:** ready-for-agent

- [ ] Every list renders as a bullet list, not as a code block
- [ ] The first line is italicised and names the 42 curriculum and both logins
- [ ] The Description section explains the project's goal and gives a brief overview
- [ ] The Instructions section has working clone and run steps, with the real repository URL and directory name, and lists every Makefile target with what it does
- [ ] The complete config file format is documented — every mandatory key, every optional key, accepted value types, and comment syntax
- [ ] The generation algorithm and the solving algorithm are named separately, so a reader knows which does which
- [ ] A visible placeholder addressed to its owner stands in for the algorithm justification
- [ ] The section stating what is reusable and how matches what the package actually contains
- [ ] The module documentation is repeated here in full
- [ ] The output analyser has a section describing what it checks and how to run it
- [ ] Error handling behaviour is described, so a reader knows what happens with bad input
- [ ] Team roles, the anticipated plan, and how it evolved are recorded
- [ ] What worked and what could be improved are both recorded, honestly
- [ ] The tools used are listed
- [ ] A visible placeholder addressed to its owner stands in for the classic references
- [ ] The AI usage disclosure is retained
- [ ] The required Python version is 3.10, matching the subject and the package metadata
- [ ] Placeholders are visible in rendered Markdown, never hidden in comments, so an unfilled section cannot ship unnoticed
