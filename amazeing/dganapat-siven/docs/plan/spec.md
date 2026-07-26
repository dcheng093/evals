# Spec — Documentation, License, and Packaging for A-Maze-ing

Source: `A-Maze-ing.pdf` v2.1, Chapters III.3, VI and VII.

## Problem Statement

A peer evaluator opens this repository to grade it against the A-Maze-ing subject. Three of the graded deliverables are missing or broken, and none of the failures are visible until someone actually tries to use them.

The reusable maze generator is not reusable. The subject requires the generation logic to live in a standalone module, installable by pip, distributed as a `mazegen-*` artifact committed at the repository root. No such artifact exists. The package metadata that would produce one discovers zero packages, because the generation code is a set of loose top-level modules and no directory in the repository is a Python package. Building today yields a distribution containing no code. Nothing named `mazegen` is importable at all, so the evaluator's first instinct — install it and import it — fails immediately.

The documentation the subject demands does not exist. Chapter VI requires a short document describing how to instantiate the generator, pass custom parameters, and reach the generated structure and a solution — and requires that document to travel inside the distributed package. Chapter VII requires the same document to appear in the main README, alongside the config file format, the algorithm choice and its justification, a statement of what is reusable, the team's planning and how it evolved, a retrospective, the tools used, and classic references. The main README covers roughly a third of that list. Every list in it is indented four spaces, which in Markdown renders as a code block, so the document a stranger is supposed to read to "quickly understand what the project is about" displays as grey monospace boxes.

The license file is not a license. It is the opening clause of the MIT license, truncated mid-sentence, followed by a sentence of plain English with no legal effect. The warranty disclaimer is absent. Only one of the two team members is named in the copyright line. The package metadata points at this file, so the broken text is what ships to anyone who installs the package.

## Solution

The maze generation code becomes a real Python package named `mazegen`, containing the maze structure, the generator, and the solver. A future project installs the built artifact and writes `from mazegen import MazeGenerator`. That import working from a clean virtual environment is the single fact that proves the reusability requirement is satisfied.

A single Makefile target builds the distribution directly into the repository root, so the committed artifact and the rebuild-from-source step the evaluator performs live are the same one command. The artifact is versioned `1.0.0`, matching the example filename in the subject.

The package carries its own documentation. A module README describes instantiation with a worked example, the custom parameters a caller can pass, and how to reach both the maze structure and a solution. Package metadata names this file as the package readme, which is what causes it to travel inside the distribution rather than merely sitting beside it.

The main README is rewritten to satisfy Chapter VII in full: correctly rendering Markdown, the complete config file format, the algorithms used for generation and for solving, what is reusable and how, the module documentation repeated verbatim, the team's roles and planning, an honest retrospective, the tools used, and references. Two sections the author cannot honestly write — the justification for the algorithm choice, which belongs to the teammate who made it, and the list of sources actually read — are left as visible placeholders rather than invented.

The license becomes the complete MIT text, warranty disclaimer included, naming both team members, and is declared in package metadata using the current standard form.

## User Stories

### Peer evaluator

1. As a peer evaluator, I want to find a `mazegen-*` artifact at the root of the repository, so that I can confirm the Chapter VI deliverable exists without hunting through directories.
2. As a peer evaluator, I want the artifact's filename to match the `mazegen-*` pattern the subject specifies, so that I can tick the naming requirement without interpretation.
3. As a peer evaluator, I want to create a fresh virtual environment, install the build tooling, and rebuild the package from source, so that I can confirm the committed artifact was genuinely produced from the code in front of me.
4. As a peer evaluator, I want the rebuild to be a single documented command, so that the live rebuild step does not consume the evaluation slot.
5. As a peer evaluator, I want the rebuild to complete without deprecation warnings, so that I am not left judging whether a warning is a failure.
6. As a peer evaluator, I want to install the built artifact and import the generator class, so that I can verify the module is genuinely reusable rather than merely claimed to be.
7. As a peer evaluator, I want to generate a maze through the installed package alone, with no other repository file present, so that I can confirm the module is standalone.
8. As a peer evaluator, I want the installed package to expose exactly one generation class, so that I can match it against the subject's requirement for a unique class.
9. As a peer evaluator, I want to read documentation that ships inside the distribution, so that I can confirm code and documentation are available together in a single file as the subject requires.
10. As a peer evaluator, I want the main README's first line to be italicised and to name the 42 curriculum and both logins, so that I can tick the first Chapter VII requirement at a glance.
11. As a peer evaluator, I want the main README to render as formatted prose and bullet lists, so that I can read it rather than decode it.
12. As a peer evaluator, I want the complete config file format documented, including every mandatory key, every optional key, accepted value types, and comment syntax, so that I can write my own config file and exercise the program.
13. As a peer evaluator, I want to know which algorithm generates the maze and which finds the path, so that I can ask the team about the right one.
14. As a peer evaluator, I want a justification for the algorithm choice, so that I can test whether the team understands the alternatives.
15. As a peer evaluator, I want an explicit statement of which part of the code is reusable and how, so that I can check the claim against the package contents.
16. As a peer evaluator, I want the module documentation repeated in the main README, so that I can read it without unpacking the distribution.
17. As a peer evaluator, I want each team member's role documented, so that I can direct questions to the person who did the work.
18. As a peer evaluator, I want the team's anticipated plan and how it changed, so that I can assess whether the team reflected on its process.
19. As a peer evaluator, I want an honest account of what worked and what did not, so that I can distinguish reflection from marketing.
20. As a peer evaluator, I want the tools the team used listed, so that I understand their working environment.
21. As a peer evaluator, I want classic references on maze generation listed, so that I can check the team read around the topic.
22. As a peer evaluator, I want the AI usage disclosure retained, so that the Chapter II requirement stays satisfied.
23. As a peer evaluator, I want a complete license naming both authors, so that the repository's terms of reuse are unambiguous.
24. As a peer evaluator, I want the program to still run correctly after the restructure, so that a packaging change has not broken the mandatory part.
25. As a peer evaluator, I want lint and type checks to still pass after the restructure, so that the Chapter III standards remain met.
26. As a peer evaluator, I want the generated output file to still validate as coherent after the restructure, so that Chapter IV.5 remains satisfied.
27. As a peer evaluator, I want a request for a small live modification to be easy to make, so that the understanding check fits in the time allowed.

### Developer reusing the module

28. As a developer starting a new project, I want to install the maze generator from a distribution file, so that I do not have to copy source files between repositories.
29. As a developer, I want the package name and the import name to be the same word, so that I do not have to guess what to type after installing.
30. As a developer, I want a single import to give me the generator class, so that I can start without reading the package layout.
31. As a developer, I want a worked example I can paste and run, so that my first attempt succeeds.
32. As a developer, I want to set the maze dimensions when I construct the generator, so that I can produce a maze that fits my application.
33. As a developer, I want to supply a seed, so that my output is reproducible across runs.
34. As a developer, I want to control whether the maze is perfect, so that I can choose between a single-solution maze and a looping board.
35. As a developer, I want to specify entry and exit positions, so that the maze fits my level design.
36. As a developer, I want documentation of every constructor parameter and its default, so that I know what I can change without reading the source.
37. As a developer, I want access to the generated maze structure, so that I can render it my own way.
38. As a developer, I want the structure's shape documented, so that I can traverse it without guessing.
39. As a developer, I want to be told that the in-memory structure differs from the output file's hexadecimal encoding, so that I do not assume they are interchangeable.
40. As a developer, I want access to a solution path, so that I can display or verify the route without writing my own solver.
41. As a developer, I want to know the solution is the shortest path, so that I can rely on it for scoring or hints.
42. As a developer, I want the module to have no dependencies beyond the standard library, so that installing it does not drag in a dependency tree.
43. As a developer, I want the module to work without the project's config file parser, so that I can use my own configuration format.
44. As a developer, I want the module to work without the project's terminal renderer, so that I can draw to a canvas or an image instead.
45. As a developer, I want installing the package to add exactly one name to my environment, so that it does not collide with my own modules.
46. As a developer, I want the package's license visible after installation, so that I know the terms without visiting the repository.
47. As a developer, I want documentation available offline after installation, so that I can read it without the source repository.

### Team member

48. As a team member, I want the module documentation and the main README to state the same thing, so that a reader is not given two conflicting accounts.
49. As a team member, I want the sections only my teammate can answer marked visibly, so that they are noticed and filled rather than shipped empty.
50. As a team member, I want placeholders to be visible in rendered Markdown rather than hidden in comments, so that an unfilled section cannot ship silently.
51. As a team member, I want the retrospective to record what actually happened, so that I can defend it under questioning.
52. As a team member, I want the required Python version stated identically in the README and the package metadata, so that no reader is misled about what they need.
53. As a team member, I want a version control ignore file covering Python artefacts, so that caches and the virtual environment stay out of the repository.
54. As a team member, I want that ignore file to deliberately not exclude the built distribution, so that the artefact the subject requires is not silently dropped.
55. As a team member, I want the reason for that exception written down in the file, so that a future contributor does not "fix" it.
56. As a team member, I want the clean target to leave the distribution untouched, so that housekeeping does not delete a graded deliverable.
57. As a team member, I want the build to ignore the virtual environment when discovering packages, so that installed third-party code is never swept into our distribution.
58. As a team member, I want our own output analyser documented in the README, so that the verification work we did is visible to a reader.
59. As a team member, I want to rebuild and reinstall the package in one command, so that I can check my changes quickly.

### Newcomer

60. As someone who has never seen this project, I want a description that explains what it does in a few sentences, so that I can decide whether to keep reading.
61. As someone cloning the repository, I want accurate clone and run instructions, so that my first attempt works.
62. As someone cloning the repository, I want every Makefile target listed and explained, so that I know what is available.
63. As someone reading the README, I want the error handling behaviour described, so that I know what the program does with bad input.
64. As a recruiter skimming the repository, I want the README to render correctly on the hosting platform, so that my first impression is of finished work.

## Implementation Decisions

### Package structure

- The maze generation code becomes a Python package named `mazegen`, containing three modules: the maze structure, the generator, and the solver. This is the scope the subject's phrase "maze generation" covers.
- Config file parsing and terminal rendering stay outside the package as main-program code. They belong to Chapter IV and Chapter V respectively, not to Chapter VI, and a future consumer will have its own configuration format and its own renderer.
- The main program, the output analyser, and the default config file remain at the repository root. The subject fixes the main program's filename and requires a default config in the repository.
- The package's public surface re-exports the generator class, the maze structure type, and the solver function. A caller writes a single import and needs no knowledge of the internal module split.
- The generator class remains the single generation class. The maze structure stays a separate data type, which the subject sanctions by describing the module as granting access to the maze structure.
- The hexadecimal output encoder and the path-to-direction converter stay alongside the generator. They are output-format concerns rather than generation, but separating them buys nothing the evaluation rewards and costs an extra module move.
- Modules internal to the package import each other by their new package-relative names. The main program and the renderer import from the package's public surface.

### Distribution

- The distribution is named `mazegen`, satisfying the subject's `mazegen-*` requirement.
- The version becomes `1.0.0`, matching the example filename in the subject. The existing `0.1.0` would pass the letter of the rule but reads as unfinished work on a final submission.
- Package discovery is restricted to names beginning with `mazegen`. Without this restriction, discovery walks every subdirectory looking for packages and will sweep the contents of the virtual environment into the distribution once the install target has been run. This is the single most likely cause of a build that appears to succeed and produces a corrupt artefact.
- A build target writes the distribution directly to the repository root, avoiding a separate output directory and the copy step that would otherwise be needed to satisfy the subject's "at the root of your git repository" requirement.
- Both the wheel and the source distribution are produced. The subject permits either.
- The build tool is added to the dependencies the install target installs, so that the evaluator's live rebuild is two documented commands with nothing installed by hand.
- The install target upgrades pip before installing tools rather than after.
- The clean target continues to remove only caches. It must not be extended to remove distributions.
- The version control ignore file covers Python caches, compiled files, and the virtual environment, and deliberately omits distribution artefacts. A comment in the file records why, because every stock template for this file excludes them.

### Documentation

- The package carries its own readme, covering instantiation with a runnable example, the parameters a caller may pass and their defaults, how to reach the generated structure, and how to reach a solution.
- Package metadata names the package readme as the distribution's readme. This is the mechanism by which the documentation travels inside the artefact: a Markdown file placed in a package directory is not included in a wheel by default, whereas the file named as the readme becomes the distribution's description metadata.
- Package data configuration is not added. The metadata route already satisfies the requirement that code and documentation be available in a single file.
- The main README repeats the module documentation, as Chapter VII requires. The duplication is mandated by the subject and will drift; there is no way to avoid it.
- The main README's list formatting is corrected. The current four-space indentation renders every list as a code block.
- The required Python version is stated as 3.10 throughout, matching the subject and the package metadata. The README's current claim of 3.11 is corrected.
- The clone instruction is completed with the real repository URL and directory name.
- The output analyser gains a README section describing what it checks and how to run it.
- The two sections that cannot be honestly authored — the justification for the algorithm choice, and the list of sources actually read — are left as visible blockquote placeholders addressed to their owner. Visible rather than hidden, so an unfilled section cannot ship unnoticed.
- Recorded content for the planning and retrospective sections: the team researched the topic first, was initially unsure how to divide the work, and settled on splitting by component because the components were loosely coupled and could be worked on in parallel; cleanup and documentation were done jointly at the end. What worked: the component split, and building the Makefile early so the compile-and-rerun loop was one command. What could be improved: the team exchanged files directly instead of using version control and should learn a proper git workflow; and no unit tests were written, with output verified by the project's own analyser instead, where a test suite would have caught regressions earlier.
- Tools recorded: flake8, mypy, make, virtual environments, git, VS Code, the project's own output analyser, and AI. The file-sharing mechanism is deliberately not named.

### License

- The license file becomes the complete MIT text including the warranty disclaimer.
- The copyright line names both team members.
- Package metadata declares the license using the SPDX identifier form with a separate license-files entry. The current table form is deprecated in recent versions of the build backend and emits a warning during the exact command the evaluator runs live.

## Testing Decisions

### What makes a good test here

This project has no test framework and the subject does not grade one. Verification is therefore behavioural and run through the interfaces a real consumer uses, never through internal functions. A check that imports an internal module or asserts on a private structure would pass while the deliverable is still broken, which is precisely the failure mode this work exists to fix: the current package metadata is internally consistent and still produces an empty distribution.

Every check below observes the system from outside, exactly as an evaluator would.

### The one new seam

The installed package's public surface. From a virtual environment containing nothing but the built artifact, and from a working directory containing none of the project's source:

- Import the generator class by the package name.
- Construct it with explicit dimensions and a seed.
- Generate a maze and reach the resulting structure.
- Reach a solution.
- Generate twice with the same seed and confirm the results match.

This single seam covers the package layout decision, the distribution's contents, the import-name decision, and the Chapter VI reusability claim. It is the highest available point: everything below it is exercised transitively, and nothing above it exists.

Working outside the repository is not incidental. Running from the repository root would import the source tree rather than the installed package and would pass even if the distribution were empty.

### Existing seams, reused

- **The main program's run target.** Runs the whole application against the default config. Proves the restructure did not break the mandatory part. Prior art: this is the subject's own mandated invocation.
- **The output analyser.** Validates wall coherence between neighbouring cells and the perfect-versus-playable property of the generated file. Proves the restructure did not change generated output. Prior art: written by the team for exactly this purpose and already the project's strongest verification tool.
- **The lint target.** Runs flake8 and mypy across the tree. Proves the new package layout is still standards-compliant and fully typed. Prior art: mandated by Chapter III.2 and already present.

### Documentation verification

- The module documentation's example is executed as written against the installed package. A documented example that does not run is worse than no example, and this one is the first thing a reader will try.
- The distribution is inspected to confirm the documentation is present in it, rather than assumed present because the metadata names it.
- The main README is checked as rendered Markdown, not as source, since the defect being fixed is a rendering defect invisible in plain text.

### Not being added

No test framework, no test directory, no unit tests. The subject makes them explicitly optional and ungraded, and the four seams above cover every behaviour this work changes. Adding a framework would expand the diff without improving what an evaluator can verify.

## Out of Scope

- The unbounded recursion in the depth-first generator. It allocates one stack frame per cell, so a maze above roughly a thousand cells raises a recursion error. The default configuration is well inside the safe range. This is a real defect and an evaluator who enlarges the config will find it, but it is a correctness fix in the mandatory part, not documentation, licensing, or packaging.
- A Makefile target for the output analyser. Considered and declined.
- Any change to the generation algorithm, the solver, the renderer, or the config parser beyond the import statements the restructure requires.
- Unit tests and a test framework.
- Git commits, branches, and history. The work is left staged for the team to commit.
- Publication to any package index. The subject requires an artifact in the repository, not a public release.
- The bonus features in Chapter VIII.

## Further Notes

- The subject's phrase "available in a single file suitable for a later installation by pip" refers to the built distribution, not to a single source file. The following sentences confirm this by naming the permitted extensions and giving an example wheel filename. A single-source-file interpretation was considered and rejected.
- Committing a build artifact contradicts normal practice. The subject requires it explicitly, and the ignore file must be written with that in mind.
- The subject requires the module documentation in two places. The duplication is deliberate on the subject's part and cannot be factored away.
- The repository currently has a single commit and no branches, so version control history offers no record of how the work evolved. The planning section is therefore written from the team's recollection, and this is itself the substance of the retrospective's main regret.
- Chapter II warns specifically against submitting content the author cannot explain under questioning. This is why the algorithm justification and the reference list are left as placeholders for their owner rather than filled with plausible text.
