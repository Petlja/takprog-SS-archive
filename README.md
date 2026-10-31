# Takprog archive

Tasks from Serbian informatics competitions (Takprog), restored from Petlja and checked, for the competition
archive. Each task has everything needed to set it again: statement with examples, tests, checker (or grader), scoring,
time and memory limits, and the written solution. The tasks are under CC BY, as the competition commission publishes them.

## Layout

Paths follow the archive's own scheme: `takprog-{season}/{round}/{nn}_{task}/`.

| File | What |
|---|---|
| `README.md` | What was found and fixed, in a few lines |
| `task.yaml` | Title, limits, test count, and where every part came from on Petlja (problem, test version, competitions) |
| `statement.md` | The statement in petljapub format, with examples |
| `editorial.md` | The written solution (how to solve the task, in prose), when there is one |
| `testcases/` | `NN.in` / `NN.out`: the test set the competition actually ran on |
| `checker.cpp` | The competition's checker, when it had one. Called as `checker <contestant output> <expected output> <input>`; exit code 0 = accepted |
| `scoring.yaml` | The competition's scoring: subtasks, points, public tests |

## How a task gets here

**Tests, limits, checker and scoring come from the competition on Petlja**, as the contest ran. They are taken byte
for byte from the problem's test version that was live on the contest date, after comparing every copy on Petlja: all
test versions, the competition, its testing and archive copies. The 2024 collection (`takprog-SS-zbirka-2024`) is not
used for these: it has fewer tests and different limits. Only the **statement and editorial**,
which the collection shares with the competition, come from it.

The collection's author solutions are run against the chosen testcases in a copy of Petlja's grader before the task is added. Anything
that couldn't be found is listed in the task's `README.md`, for the authors to fill in.

## Tasks

| Season | Round | Task | Status |
|---|---|---|---|
| 2021-22 | Državno | [Jednačine](takprog-2021-22/05_DRZ/01_jednacine) | complete |
