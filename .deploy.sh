#!/bin/bash
if [ "$TRAVIS_BRANCH" == "master" ]; then
source ~/virtualenv/python2.7/bin/activate
pip install copr-cli simplejson jinja2
openssl aes-256-cbc -K $encrypted_403c23673bf1_key -iv $encrypted_403c23673bf1_iv -in .copr.enc -out .copr -d
copr-cli --config .copr build --nowait ${COPR_REPOSITORY} *.src.rpm
sudo apt-get install alien
sudo alien *[^src].rpm
sudo gem install package_cloud
package_cloud yank dvdmuckle/minsh/ubuntu/trusty *.deb
package_cloud push dvdmuckle/minsh/ubuntu/trusty *.deb
package_cloud yank dvdmuckle/minsh/ubuntu/xenial *.deb
package_cloud push dvdmuckle/minsh/ubuntu/xenial *.deb
else
	echo "Not on master branch, not deploying"
fi
