Tdot Core staging tree 0.12.3
===============================

https://www.Tdotcoin.com


What is TdotCoin?
----------------

Ovo is an experimental digital currency that enables anonymous, instant payments to anyone, anywhere in the world. Ovo uses peer-to-peer technology to operate with no central authority: managing transactions and issuing money are carried out collectively by the network. X11 Algorythm Hybrid PoW / PoS Blockchain. Master Nodes can be purchased for 10,000  Tdot's. Premined amount = 0 . In order to do a clean launch, we plan to launch on 12/30/2018 11:46PM. Master Nodes will be rewarded a higher rate of return on their investment. Similar to a bond note where you recieve a return on your investment per annum at specified amounts. However, unlike bond notes, you do not recieve your investment back, only reap a high rate of return on your investment. Tdot Core is a fork of Dash / DarkCoin pre-spork. The reason we choose to use a premined amount of 0 is because unlike the release of dash , where 2 million Dash's were insta-mined within 24 hours due to a bug in their code. Even though we could easily justify a premined amount to pay our developers and to secure us from DDoS threats, we already have a strong base and a foothold in DDoS protected Datacenters world wide. Tdot Core's developers plan to have all these issues fixed and plans to launch all bip heights sequentially within 5 years.  The reason X11 Algorythms will be at the Core of Tdot Core's encryption, over Scrypt, is because it over  10% faster and offers other benefits such as auto switching between 11 different algorythms. 10,0000 Tdot's are not easily attainable. Only from proof of work and verification of the blockchain, will miners be rewarded. Therefore mining Tdot's, Tdot miners/early adoptors will be rewarded , not only generating blocks, but also a percentage return that sees no deflation. Generating cocurrency interchange, however requires a lot of power useage and is not easily performed. Generating a hash requires a complex energy consuming mathametical computation that requires much work. Furthermore, once the blockchain attains a certan size difficulty increases exponentially. With automatic difficulty retargeting, 51% become nearly impossible. These coins could not be generated any other way. For this to be done the main network must be protected from DDoS attacks. The reason for choosing DDoS IPv4 IP's is for the following reasons: They can be encoded into IPv6 Hex's easily. They are harder to DDoS because they must be run through a program called wireshark in order to decipher. Tdot Core proposes to create a complete Supply chain including resolving issues in order placements from security and paying employees, subdivisions/partners, advertisers, and research and development. Ovo Core is the name of the open source software which enables the use of this currency.

For more information, as well as an immediately useability, compiled binary version of
the Ovo Core software, see https://www.Tdotcoin.org/.


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

Translators should also follow the [forum](https://www.Tdotcoin.ca/forum/topic/ovo-worldwide-collaboration.88/).
