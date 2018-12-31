OVO Core staging tree 0.12.3
===============================

https://www.ovocoin.com


What is OVOCoin?
----------------

Ovo is an experimental digital currency that enables anonymous, instant
payments to anyone, anywhere in the world. Ovo uses peer-to-peer technology
to operate with no central authority: managing transactions and issuing money
are carried out collectively by the network. X11 Algorythmm Hybrid PoW / PoS Blockchain.
Master/Dispensenodes can be purchased for 10,000  OVO's. Premined amount = 0 . Launch Date: 12/30/2018 11:46PM. Dispense Nodes will be rewarded a higher
rate of return on their investment. Similar to a bond note where you recieve a return on your
investment per annum at specified amounts. However, unlike bond notes, you do not recieve your
investment back at a later year, you only receive a high rate of return on your investment.
OVO Core is a Latest fork of Dash / DarkCoin. The reason we choose to use X11 Algorythms over others is
because it switches to 11 different sequences to deter ASIC activity which
helps to decentrilzie not only the mining aspect of it, but also stakes.
Since 10,0000 OVO's are not easily atainable and prooof of work must be generated,
miners need to be rewarded. Therefore for mining OVO's early adoptors will be rewarded
for not only generating blocks, but also generating cocurrency interchange.  With the 
legalization of  marijiuana, Dispenseries all over the world need scientific
pot for study. OVO Core prooposes to modify Dash coin into a marketplace not onlhy for
marijuana, but also for a a complete Suply chain including resolving issues
in order placements and security, aswell as paying employees as well as 
subdivisions/partners, advertisers, anonymously
Ovo Core is the name of the open source software which enables the use of this currency.

For more information, as well as an immediately useable, binary version of
the Ovo Core software, see https://www.ovocoin.org/.


License
-------

Ovo Core is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see https://opensource.org/licenses/MIT.

Development Process
-------------------

The `master` branch is meant to be stable. Development is normally done in separate branches.
[Tags](https://github.com/minblock/ovo/tags) are created to indicate new official,
stable release versions of Ovo Core.

The contribution workflow is described in [CONTRIBUTING.md](CONTRIBUTING.md).

Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write [unit tests](src/test/README.md) for new code, and to
submit new unit tests for old code. Unit tests can be compiled and run
(assuming they weren't disabled in configure) with: `make check`. Further details on running
and extending unit tests can be found in [/src/test/README.md](/src/test/README.md).

There are also [regression and integration tests](/qa) of the RPC interface, written
in Python, that are run automatically on the build server.
These tests can be run (if the [test dependencies](/qa) are installed) with: `qa/pull-tester/rpc-tests.py`

The Travis CI system makes sure that every pull request is built for Windows, Linux, and OS X, and that unit/sanity tests are run automatically.

### Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the
code. This is especially important for large or high-risk changes. It is useful
to add a test plan to the pull request description if testing the changes is
not straightforward.

Translations
------------

Changes to translations as well as new translations can be submitted to
[Ovo Core's Transifex page](https://www.transifex.com/projects/p/ovo/).

Translations are periodically pulled from Transifex and merged into the git repository. See the
[translation process](doc/translation_process.md) for details on how this works.

**Important**: We do not accept translation changes as GitHub pull requests because the next
pull from Transifex would automatically overwrite them again.

Translators should also follow the [forum](https://www.ovocoin.ca/forum/topic/ovo-worldwide-collaboration.88/).
