# Takprog archive

Tasks from Serbian informatics competitions (Takprog), restored from Petlja and checked, for the competition
archive. Each task has everything needed to set it again: statement with examples, tests, checker (or grader), scoring,
time and memory limits, and author solutions. The tasks are under CC BY, as the competition commission publishes them.

## Layout

Paths follow the archive's own scheme: `takprog-{season}/{round}/{nn}_{task}/`.

| File | What |
|---|---|
| `README.md` | What was found and fixed, in a few lines |
| `task.yaml` | Title, limits, test count, and where every part came from on Petlja (problem, test version, competitions) |
| `statement.md` | The statement in petljapub format, with examples |
| `editorial.md` | The written solution, when there is one |
| `tests/` | `NN.in` / `NN.out`: the test set the competition actually ran on |
| `checker.cpp` | The competition's checker, when it had one. Called as `checker <contestant output> <expected output> <input>`; exit code 0 = accepted |
| `scoring.yaml` | The competition's scoring: subtasks, points, public tests |
| `solutions/` | Author solutions. Never contestants' code |

## How a task gets here

**Tests, limits, checker and scoring come from the competition on Petlja**, as the contest ran. They are taken byte
for byte from the problem's test version that was live on the contest date, after comparing every copy on Petlja: all
test versions, the competition, its testing and archive copies. The 2024 collection (`takprog-SS-zbirka-2024`) is not
used for these: it has fewer tests and different limits. Only the **statement, editorial and author solutions**,
which the collection shares with the competition, come from it.

The author solutions are run against the chosen tests in a copy of Petlja's grader before the task is added. Anything
that couldn't be found is listed in the task's `README.md`, for the authors to fill in.

## Tasks

| Season | Round | Task | Status |
|---|---|---|---|
| 2021-22 | Državno | [Jednačine](takprog-2021-22/05_DRZ/01_jednacine) | complete |
